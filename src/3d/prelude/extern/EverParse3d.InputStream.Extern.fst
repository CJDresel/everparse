module EverParse3d.InputStream.Extern

module B = LowStar.Buffer
module HS = FStar.HyperStack
module HST = FStar.HyperStack.ST
module U32 = FStar.UInt32
module U8 = FStar.UInt8

module Aux = EverParse3d.InputStream.Extern.Type

inline_for_extraction
noextract
let t = Aux.input_buffer

let len_all
  (x: t)
: GTot U32.t
= if x.Aux.has_length
  then x.Aux.length
  else Aux.len_all x.Aux.base

unfold
let live
  (x: t)
  (m: HS.mem)
: Tot prop
= let read = U32.v (B.deref m x.Aux.position) in
  Aux.live x.Aux.base m /\
  B.live m x.Aux.position /\
  read <= U32.v (len_all x) /\
  read == Seq.length (Aux.get_read x.Aux.base m)

let footprint
  (x: t)
: Ghost B.loc
  (requires True)
  (ensures (fun y -> B.address_liveness_insensitive_locs `B.loc_includes` y))
= Aux.footprint x.Aux.base `B.loc_union` B.loc_buffer x.Aux.position

let live_not_unused_in
    (x: t)
    (h: HS.mem)
:   Lemma
    (requires (live x h))
    (ensures (B.loc_not_unused_in h `B.loc_includes` footprint x))
= Aux.live_not_unused_in x.Aux.base h

let get_all (x: t) : Ghost (Seq.seq U8.t)
    (requires True)
    (ensures (fun y -> Seq.length y == U32.v (len_all x)))
= Seq.slice (Aux.get_all x.Aux.base) 0 (U32.v (len_all x))

let get_remaining (x: t) (h: HS.mem) : Ghost (Seq.seq U8.t)
    (requires (live x h))
    (ensures (fun y -> Seq.length y <= U32.v (len_all x)))
= let r = U32.v (B.deref h x.Aux.position) in
  Seq.slice (get_all x) r (U32.v (len_all x))

let get_read (x: t) (h: HS.mem) : Ghost (Seq.seq U8.t)
    (requires (live x h))
    (ensures (fun y -> get_all x `Seq.equal` (y `Seq.append` get_remaining x h)))
= Aux.get_read x.Aux.base h

let preserved
    (x: t)
    (l: B.loc)
    (h: HS.mem)
    (h' : HS.mem)
:   Lemma
    (requires (live x h /\ B.modifies l h h' /\ B.loc_disjoint (footprint x) l))
    (ensures (
      live x h' /\
      get_remaining x h' == get_remaining x h /\
      get_read x h' == get_read x h
    ))
=
  Aux.preserved x.Aux.base l h h'

open LowStar.BufferOps

inline_for_extraction
noextract
let has
    (x: t)
    (n: U32.t)
:   HST.Stack bool
    (requires (fun h -> live x h))
    (ensures (fun h res h' ->
      B.modifies B.loc_none h h' /\
      (res == true <==> Seq.length (get_remaining x h) >= U32.v n)
    ))
=
  if x.Aux.has_length
  then
    let position = !* x.Aux.position in
    n `U32.lte` (x.Aux.length `U32.sub` position)
  else
    Aux.has x.Aux.base n

inline_for_extraction
noextract
let read
    (x: t)
    (n: U32.t)
    (dst: B.buffer U8.t)
:   HST.Stack (B.buffer U8.t)
    (requires (fun h ->
      live x h /\
      B.live h dst /\
      B.loc_disjoint (footprint x) (B.loc_buffer dst) /\
      B.length dst == U32.v n /\
      Seq.length (get_remaining x h) >= U32.v n
    ))
    (ensures (fun h dst' h' ->
      let s = get_remaining x h in
      B.modifies (B.loc_buffer dst `B.loc_union` footprint x) h h' /\
      B.as_seq h' dst' `Seq.equal` Seq.slice s 0 (U32.v n) /\
      live x h' /\
      B.live h' dst' /\
      (B.loc_buffer dst `B.loc_union` footprint x) `B.loc_includes` B.loc_buffer dst' /\
      get_remaining x h' `Seq.equal` Seq.slice s (U32.v n) (Seq.length s)
    ))
= let dst = Aux.read x.Aux.base n dst in
  let h1 = HST.get () in
  let position = !* x.Aux.position in
  x.Aux.position *= position `U32.add` n;
  let h2 = HST.get () in
  Aux.preserved x.Aux.base (B.loc_buffer x.Aux.position) h1 h2;
  dst

inline_for_extraction
noextract
let skip
    (x: t)
    (n: U32.t)
:   HST.Stack unit
    (requires (fun h -> live x h /\ Seq.length (get_remaining x h) >= U32.v n))
    (ensures (fun h _ h' ->
      let s = get_remaining x h in
      B.modifies (footprint x) h h' /\
      live x h' /\
      get_remaining x h' `Seq.equal` Seq.slice s (U32.v n) (Seq.length s)
    ))
= Aux.skip x.Aux.base n;
  let h1 = HST.get () in
  let position = !* x.Aux.position in
  x.Aux.position *= position `U32.add` n;
  let h2 = HST.get () in
  Aux.preserved x.Aux.base (B.loc_buffer x.Aux.position) h1 h2

inline_for_extraction
noextract
let empty
    (x: t)
:   HST.Stack unit
    (requires (fun h -> live x h))
    (ensures (fun h _ h' ->
      B.modifies (footprint x) h h' /\
      live x h' /\
      get_remaining x h' `Seq.equal` Seq.empty
    ))
=
  if x.Aux.has_length
  then begin
    let h0 = HST.get () in
    let position = !* x.Aux.position in
    let h1 = HST.get () in
    Aux.preserved x.Aux.base (B.loc_buffer x.Aux.position) h0 h1;
    Aux.skip x.Aux.base (x.Aux.length `U32.sub` position);
    let h2 = HST.get () in
    x.Aux.position *= x.Aux.length;
    let h3 = HST.get () in
    Aux.preserved x.Aux.base (B.loc_buffer x.Aux.position) h2 h3
  end else begin
    let skipped = Aux.empty x.Aux.base in
    let h2 = HST.get () in
    let position = !* x.Aux.position in
    x.Aux.position *= position `U32.add` skipped;
    let h3 = HST.get () in
    Aux.preserved x.Aux.base (B.loc_buffer x.Aux.position) h2 h3
  end

inline_for_extraction
let get_read_count
    (x: t)
:   HST.Stack U32.t
    (requires (fun h -> live x h))
    (ensures (fun h res h' ->
      B.modifies B.loc_none h h' /\
      U32.v res == Seq.length (get_read x h)
    ))
= let h2 = HST.get () in
  let read = !* x.Aux.position in
  let h3 = HST.get () in
  Aux.preserved x.Aux.base (B.loc_buffer x.Aux.position) h2 h3;
  read

let is_prefix_of
    (x: t)
    (y: t)
:   Tot prop
= x.Aux.base == y.Aux.base /\
  x.Aux.position == y.Aux.position /\
  (y.Aux.has_length == true ==>
    (x.Aux.has_length == true /\
    U32.v x.Aux.length <= U32.v y.Aux.length))

let get_suffix
    (x: t)
    (y: t)
:   Ghost (Seq.seq U8.t)
    (requires (x `is_prefix_of` y))
    (ensures (fun _ -> True))
= Seq.slice (get_all y) (U32.v (len_all x)) (U32.v (len_all y))

let is_prefix_of_prop
    (x: t)
    (y: t)
    (h: HS.mem)
:   Lemma
    (requires (
      live x h /\
      x `is_prefix_of` y
    ))
    (ensures (
      live y h /\
      get_read y h `Seq.equal` get_read x h /\
      get_remaining y h `Seq.equal` (get_remaining x h `Seq.append` get_suffix x y)
    ))
=
  ()

inline_for_extraction
noextract
let truncate
    (x: t)
    (n: U32.t)
:   HST.Stack t
    (requires (fun h ->
      live x h /\
      U32.v n <= Seq.length (get_remaining x h)
    ))
    (ensures (fun h res h' ->
      B.modifies B.loc_none h h' /\
      res `is_prefix_of` x /\
      footprint res == footprint x /\
      live res h' /\
      Seq.length (get_remaining res h') == U32.v n
    ))
= let h2 = HST.get () in
  let read = !* x.Aux.position in
  let h3 = HST.get () in
  Aux.preserved x.Aux.base (B.loc_buffer x.Aux.position) h2 h3;
  {
    Aux.base = x.Aux.base;
    Aux.has_length = true;
    Aux.position = x.Aux.position;
    Aux.length = read `U32.add` n;
    Aux.prf = ();
  }
