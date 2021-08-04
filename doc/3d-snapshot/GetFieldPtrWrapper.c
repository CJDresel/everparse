#include "GetFieldPtrWrapper.h"
#include "EverParse.h"
#include "GetFieldPtr.h"
void GetFieldPtrEverParseError(const char *StructName, const char *FieldName, const char *Reason);

static
void DefaultErrorHandler(
	const char *typename,
	const char *fieldname,
	const char *reason,
	uint8_t *context,
	EverParseInputBuffer input,
	uint64_t start_pos)
{
	EverParseErrorFrame *frame = (EverParseErrorFrame*)context;
	EverParseDefaultErrorHandler(
		typename,
		fieldname,
		reason,
		frame,
		input,
		start_pos
	);
}

BOOLEAN GetFieldPtrCheckT(uint8_t** out, uint8_t *base, uint32_t len) {
	EverParseErrorFrame frame;
	frame.filled = FALSE;
	EverParseInputBuffer input = EverParseMakeInputBuffer(base, len);
	uint64_t result = GetFieldPtrValidateT(out,  (uint8_t*)&frame, &DefaultErrorHandler, input, 0);
	if (EverParseIsError(result))
	{
		if (frame.filled)
		{
			GetFieldPtrEverParseError(frame.typename, frame.fieldname, frame.reason);
		}
		return FALSE;
	}
	return TRUE;
}
