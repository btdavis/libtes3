#ifndef TES3RECORDTYPE_H
#define TES3RECORDTYPE_H

#include <cstdint>

using TES3RecordType = uint32_t;

constexpr bool IsCharLiteralBigEndian()
{
	return ('\01\02\03\04' == 0x01020304);
}

constexpr TES3RecordType MakeRecordType(uint32_t value)
{
	if (!IsCharLiteralBigEndian())
	{
		return ((value & 0x000000FF) << 24) | ((value & 0x0000FF00) << 8) | ((value & 0x00FF0000) >> 8) | ((value & 0xFF000000) >> 24);
	}
	else
	{
		return value;
	}
}

#endif
