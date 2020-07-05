#ifndef TES3RECORD_H
#define TES3RECORD_H

#include "TES3RecordType.h"
#include "TES3SubrecordIterator.h"
#include "MemoryReader.h"

#include <vector>
#include <optional>

class TES3Record
{
public:
	TES3Record(MemoryReader& reader);

	MemoryReader data() const;

	TES3SubrecordIterator begin() const;
	TES3SubrecordIterator end() const;

	TES3RecordType type() const;
	uint32_t header() const;
	uint32_t flags() const;

	std::optional<TES3Subrecord> firstSubrecord(TES3RecordType type) const;
	std::vector<TES3Subrecord> allSubrecords(TES3RecordType type) const;

protected:
	MemoryReader m_reader;
	TES3RecordType m_type = 0;
	uint32_t m_header = 0;
	uint32_t m_flags = 0;
};

#endif
