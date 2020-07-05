#ifndef TES3SUBRECORD_H
#define TES3SUBRECORD_H

#include <optional>
#include "TES3RecordType.h"
#include "MemoryReader.h"

class TES3Subrecord
{
public:
	TES3Subrecord(MemoryReader& reader);

	MemoryReader data() const;

	TES3RecordType type() const;

private:
	MemoryReader m_reader;
	TES3RecordType m_type = 0;
};

#endif
