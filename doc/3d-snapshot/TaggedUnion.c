

#include "TaggedUnion.h"

#define SIZE8 ((uint8_t)8U)

#define SIZE16 ((uint8_t)16U)

#define SIZE32 ((uint8_t)32U)

static inline uint64_t
ValidateIntPayloadValue32(
  uint8_t *Ctxt,
  void
  (*Err)(
    EverParseString x0,
    EverParseString x1,
    EverParseString x2,
    uint8_t *x3,
    uint8_t *x4,
    uint64_t x5
  ),
  uint8_t *Input,
  uint64_t InputLength,
  uint64_t StartPosition
)
/*++
    Internal helper function:
        Validator for field _int_payload_value32
        of type TaggedUnion._int_payload
--*/
{
  /* Validating field value32 */
  /* Checking that we have enough space for a UINT32, i.e., 4 bytes */
  BOOLEAN hasBytes = (uint64_t)4U <= (InputLength - StartPosition);
  uint64_t positionAfterIntPayload;
  if (hasBytes)
  {
    positionAfterIntPayload = StartPosition + (uint64_t)4U;
  }
  else
  {
    positionAfterIntPayload =
      EverParseSetValidatorErrorPos(EVERPARSE_VALIDATOR_ERROR_NOT_ENOUGH_DATA,
        StartPosition);
  }
  if (EverParseIsSuccess(positionAfterIntPayload))
  {
    return positionAfterIntPayload;
  }
  Err("_int_payload",
    "_int_payload_value32",
    EverParseErrorReasonOfResult(positionAfterIntPayload),
    Ctxt,
    Input,
    StartPosition);
  return positionAfterIntPayload;
}

static inline uint64_t
ValidateIntPayloadValue16(
  uint8_t *Ctxt,
  void
  (*Err)(
    EverParseString x0,
    EverParseString x1,
    EverParseString x2,
    uint8_t *x3,
    uint8_t *x4,
    uint64_t x5
  ),
  uint8_t *Input,
  uint64_t InputLength,
  uint64_t StartPosition
)
/*++
    Internal helper function:
        Validator for field _int_payload_value16
        of type TaggedUnion._int_payload
--*/
{
  /* Validating field value16 */
  /* Checking that we have enough space for a UINT16, i.e., 2 bytes */
  BOOLEAN hasBytes = (uint64_t)2U <= (InputLength - StartPosition);
  uint64_t positionAfterIntPayload;
  if (hasBytes)
  {
    positionAfterIntPayload = StartPosition + (uint64_t)2U;
  }
  else
  {
    positionAfterIntPayload =
      EverParseSetValidatorErrorPos(EVERPARSE_VALIDATOR_ERROR_NOT_ENOUGH_DATA,
        StartPosition);
  }
  if (EverParseIsSuccess(positionAfterIntPayload))
  {
    return positionAfterIntPayload;
  }
  Err("_int_payload",
    "_int_payload_value16",
    EverParseErrorReasonOfResult(positionAfterIntPayload),
    Ctxt,
    Input,
    StartPosition);
  return positionAfterIntPayload;
}

static inline uint64_t
ValidateIntPayloadValue8(
  uint8_t *Ctxt,
  void
  (*Err)(
    EverParseString x0,
    EverParseString x1,
    EverParseString x2,
    uint8_t *x3,
    uint8_t *x4,
    uint64_t x5
  ),
  uint8_t *Input,
  uint64_t InputLength,
  uint64_t StartPosition
)
/*++
    Internal helper function:
        Validator for field _int_payload_value8
        of type TaggedUnion._int_payload
--*/
{
  /* Validating field value8 */
  /* Checking that we have enough space for a UINT8, i.e., 1 byte */
  BOOLEAN hasBytes = (uint64_t)1U <= (InputLength - StartPosition);
  uint64_t positionAfterIntPayload;
  if (hasBytes)
  {
    positionAfterIntPayload = StartPosition + (uint64_t)1U;
  }
  else
  {
    positionAfterIntPayload =
      EverParseSetValidatorErrorPos(EVERPARSE_VALIDATOR_ERROR_NOT_ENOUGH_DATA,
        StartPosition);
  }
  if (EverParseIsSuccess(positionAfterIntPayload))
  {
    return positionAfterIntPayload;
  }
  Err("_int_payload",
    "_int_payload_value8",
    EverParseErrorReasonOfResult(positionAfterIntPayload),
    Ctxt,
    Input,
    StartPosition);
  return positionAfterIntPayload;
}

static inline uint64_t
ValidateIntPayload(
  uint32_t Size,
  uint8_t *Ctxt,
  void
  (*Err)(
    EverParseString x0,
    EverParseString x1,
    EverParseString x2,
    uint8_t *x3,
    uint8_t *x4,
    uint64_t x5
  ),
  uint8_t *Input,
  uint64_t InputLength,
  uint64_t StartPosition
)
{
  uint64_t positionAfterIntPayload;
  if (Size == (uint32_t)SIZE8)
  {
    /* Field _int_payload_value8 */
    uint64_t
    positionAfterIntPayload0 =
      ValidateIntPayloadValue8(Ctxt,
        Err,
        Input,
        InputLength,
        StartPosition);
    uint64_t res;
    if (EverParseIsSuccess(positionAfterIntPayload0))
    {
      res = positionAfterIntPayload0;
    }
    else
    {
      Err("_int_payload",
        "_int_payload_ite_2",
        EverParseErrorReasonOfResult(positionAfterIntPayload0),
        Ctxt,
        Input,
        StartPosition);
      res = positionAfterIntPayload0;
    }
    positionAfterIntPayload = res;
  }
  else
  {
    uint64_t positionAfterIntPayload0;
    if (Size == (uint32_t)SIZE16)
    {
      /* Field _int_payload_value16 */
      uint64_t
      positionAfterIntPayload =
        ValidateIntPayloadValue16(Ctxt,
          Err,
          Input,
          InputLength,
          StartPosition);
      uint64_t res;
      if (EverParseIsSuccess(positionAfterIntPayload))
      {
        res = positionAfterIntPayload;
      }
      else
      {
        Err("_int_payload",
          "_int_payload_ite_1",
          EverParseErrorReasonOfResult(positionAfterIntPayload),
          Ctxt,
          Input,
          StartPosition);
        res = positionAfterIntPayload;
      }
      positionAfterIntPayload0 = res;
    }
    else
    {
      uint64_t positionAfterIntPayload;
      if (Size == (uint32_t)SIZE32)
      {
        /* Field _int_payload_value32 */
        uint64_t
        positionAfterIntPayload0 =
          ValidateIntPayloadValue32(Ctxt,
            Err,
            Input,
            InputLength,
            StartPosition);
        uint64_t res;
        if (EverParseIsSuccess(positionAfterIntPayload0))
        {
          res = positionAfterIntPayload0;
        }
        else
        {
          Err("_int_payload",
            "_int_payload_ite_0",
            EverParseErrorReasonOfResult(positionAfterIntPayload0),
            Ctxt,
            Input,
            StartPosition);
          res = positionAfterIntPayload0;
        }
        positionAfterIntPayload = res;
      }
      else
      {
        uint64_t
        positionAfterIntPayload0 =
          EverParseSetValidatorErrorPos(EVERPARSE_VALIDATOR_ERROR_IMPOSSIBLE,
            StartPosition);
        uint64_t res;
        if (EverParseIsSuccess(positionAfterIntPayload0))
        {
          res = positionAfterIntPayload0;
        }
        else
        {
          Err("_int_payload",
            "_int_payload_ite_0",
            EverParseErrorReasonOfResult(positionAfterIntPayload0),
            Ctxt,
            Input,
            StartPosition);
          res = positionAfterIntPayload0;
        }
        positionAfterIntPayload = res;
      }
      if (EverParseIsSuccess(positionAfterIntPayload))
      {
        positionAfterIntPayload0 = positionAfterIntPayload;
      }
      else
      {
        Err("_int_payload",
          "_int_payload_ite_1",
          EverParseErrorReasonOfResult(positionAfterIntPayload),
          Ctxt,
          Input,
          StartPosition);
        positionAfterIntPayload0 = positionAfterIntPayload;
      }
    }
    if (EverParseIsSuccess(positionAfterIntPayload0))
    {
      positionAfterIntPayload = positionAfterIntPayload0;
    }
    else
    {
      Err("_int_payload",
        "_int_payload_ite_2",
        EverParseErrorReasonOfResult(positionAfterIntPayload0),
        Ctxt,
        Input,
        StartPosition);
      positionAfterIntPayload = positionAfterIntPayload0;
    }
  }
  if (EverParseIsSuccess(positionAfterIntPayload))
  {
    return positionAfterIntPayload;
  }
  Err("_int_payload",
    "",
    EverParseErrorReasonOfResult(positionAfterIntPayload),
    Ctxt,
    Input,
    StartPosition);
  return positionAfterIntPayload;
}

static inline uint64_t
ValidateIntegerSize(
  uint8_t *Ctxt,
  void
  (*Err)(
    EverParseString x0,
    EverParseString x1,
    EverParseString x2,
    uint8_t *x3,
    uint8_t *x4,
    uint64_t x5
  ),
  uint8_t *Input,
  uint64_t InputLength,
  uint64_t StartPosition
)
/*++
    Internal helper function:
        Validator for field _integer_size
        of type TaggedUnion._integer
--*/
{
  /* Validating field size */
  /* Checking that we have enough space for a UINT32, i.e., 4 bytes */
  BOOLEAN hasBytes = (uint64_t)4U <= (InputLength - StartPosition);
  uint64_t positionAfterInteger;
  if (hasBytes)
  {
    positionAfterInteger = StartPosition + (uint64_t)4U;
  }
  else
  {
    positionAfterInteger =
      EverParseSetValidatorErrorPos(EVERPARSE_VALIDATOR_ERROR_NOT_ENOUGH_DATA,
        StartPosition);
  }
  if (EverParseIsSuccess(positionAfterInteger))
  {
    return positionAfterInteger;
  }
  Err("_integer",
    "_integer_size",
    EverParseErrorReasonOfResult(positionAfterInteger),
    Ctxt,
    Input,
    StartPosition);
  return positionAfterInteger;
}

static inline uint64_t
ValidateIntegerPayload(
  uint32_t Size,
  uint8_t *Ctxt,
  void
  (*Err)(
    EverParseString x0,
    EverParseString x1,
    EverParseString x2,
    uint8_t *x3,
    uint8_t *x4,
    uint64_t x5
  ),
  uint8_t *Input,
  uint64_t InputLength,
  uint64_t StartPosition
)
/*++
    Internal helper function:
        Validator for field _integer_payload
        of type TaggedUnion._integer
--*/
{
  /* Validating field payload */
  uint64_t
  positionAfterInteger = ValidateIntPayload(Size, Ctxt, Err, Input, InputLength, StartPosition);
  if (EverParseIsSuccess(positionAfterInteger))
  {
    return positionAfterInteger;
  }
  Err("_integer",
    "_integer_payload",
    EverParseErrorReasonOfResult(positionAfterInteger),
    Ctxt,
    Input,
    StartPosition);
  return positionAfterInteger;
}

uint64_t
TaggedUnionValidateInteger(
  uint8_t *Ctxt,
  void
  (*Err)(
    EverParseString x0,
    EverParseString x1,
    EverParseString x2,
    uint8_t *x3,
    uint8_t *x4,
    uint64_t x5
  ),
  uint8_t *Input,
  uint64_t InputLength,
  uint64_t StartPosition
)
{
  /* Field _integer_size */
  uint64_t
  positionAfterInteger = ValidateIntegerSize(Ctxt, Err, Input, InputLength, StartPosition);
  uint64_t positionAftersize;
  if (EverParseIsSuccess(positionAfterInteger))
  {
    positionAftersize = positionAfterInteger;
  }
  else
  {
    Err("_integer",
      "size",
      EverParseErrorReasonOfResult(positionAfterInteger),
      Ctxt,
      Input,
      StartPosition);
    positionAftersize = positionAfterInteger;
  }
  if (EverParseIsError(positionAftersize))
  {
    return positionAftersize;
  }
  uint32_t size = Load32Le(Input + (uint32_t)StartPosition);
  /* Field _integer_payload */
  uint64_t
  positionAfterInteger0 =
    ValidateIntegerPayload(size,
      Ctxt,
      Err,
      Input,
      InputLength,
      positionAftersize);
  if (EverParseIsSuccess(positionAfterInteger0))
  {
    return positionAfterInteger0;
  }
  Err("_integer",
    "payload",
    EverParseErrorReasonOfResult(positionAfterInteger0),
    Ctxt,
    Input,
    positionAftersize);
  return positionAfterInteger0;
}

