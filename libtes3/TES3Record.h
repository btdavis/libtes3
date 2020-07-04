#ifndef TES3RECORD_H
#define TES3RECORD_H

#include "TES3RecordType.h"
#include "TES3SubrecordIterator.h"
#include "MemoryReader.h"

class TES3Record
{
public:
	void read(MemoryReader& reader);
	MemoryReader data() const;

	TES3SubrecordIterator begin() const;
	TES3SubrecordIterator end() const;

	uint32_t type() const;
	uint32_t header() const;
	uint32_t flags() const;

	TES3Subrecord::Optional firstSubrecord(TES3RecordType type) const;
	std::vector<TES3Subrecord> allSubrecords(TES3RecordType type) const;

protected:
	MemoryReader m_reader;
	uint32_t m_type = 0;
	uint32_t m_header = 0;
	uint32_t m_flags = 0;
};

#endif
