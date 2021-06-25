

#ifndef __GetFieldPtr_H
#define __GetFieldPtr_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "EverParse.h"


#include "Lib.h"

uint64_t
GetFieldPtrValidateT(
  uint8_t **Out,
  uint8_t *Ctxt,
  void
  (*Err)(
    EverParseString x0,
    EverParseString x1,
    EverParseString x2,
    uint8_t *x3,
    uint32_t x4,
    uint8_t *x5,
    uint64_t x6,
    uint64_t x7
  ),
  uint32_t Uu,
  uint8_t *Input,
  uint64_t StartPosition
);

#if defined(__cplusplus)
}
#endif

#define __GetFieldPtr_H_DEFINED
#endif
