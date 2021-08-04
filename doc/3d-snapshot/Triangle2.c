

#include "Triangle2.h"

static inline uint64_t
ValidateTriangleCorners(
  uint8_t *Ctxt,
  void
  (*Err)(
    EverParseString x0,
    EverParseString x1,
    EverParseString x2,
    uint8_t *x3,
    EverParseInputBuffer x4,
    uint64_t x5
  ),
  EverParseInputBuffer Input,
  uint64_t Pos
)
/*++
    Internal helper function:
        Validator for field _triangle_corners
        of type Triangle2._triangle
--*/
{
  /* Validating field corners */
  uint64_t res;
  if ((uint32_t)4U * (uint32_t)(uint8_t)3U % (uint32_t)4U == (uint32_t)0U)
  {
    BOOLEAN
    hasBytes = (uint64_t)((uint32_t)4U * (uint32_t)(uint8_t)3U) <= ((uint64_t)Input.len - Pos);
    if (hasBytes)
    {
      res = Pos + (uint64_t)((uint32_t)4U * (uint32_t)(uint8_t)3U);
    }
    else
    {
      res = EverParseSetValidatorErrorPos(EVERPARSE_VALIDATOR_ERROR_NOT_ENOUGH_DATA, Pos);
    }
  }
  else
  {
    res = EverParseSetValidatorErrorPos(EVERPARSE_VALIDATOR_ERROR_LIST_SIZE_NOT_MULTIPLE, Pos);
  }
  uint64_t positionAfterTriangle = res;
  if (EverParseIsSuccess(positionAfterTriangle))
  {
    return positionAfterTriangle;
  }
  Err("_triangle",
    "_triangle_corners",
    EverParseErrorReasonOfResult(positionAfterTriangle),
    Ctxt,
    Input,
    Pos);
  return positionAfterTriangle;
}

uint64_t
Triangle2ValidateTriangle(
  uint8_t *Ctxt,
  void
  (*Err)(
    EverParseString x0,
    EverParseString x1,
    EverParseString x2,
    uint8_t *x3,
    EverParseInputBuffer x4,
    uint64_t x5
  ),
  EverParseInputBuffer Input,
  uint64_t Pos
)
{
  /* Field _triangle_corners */
  uint64_t positionAfterTriangle = ValidateTriangleCorners(Ctxt, Err, Input, Pos);
  if (EverParseIsSuccess(positionAfterTriangle))
  {
    return positionAfterTriangle;
  }
  Err("_triangle",
    "corners",
    EverParseErrorReasonOfResult(positionAfterTriangle),
    Ctxt,
    Input,
    Pos);
  return positionAfterTriangle;
}

