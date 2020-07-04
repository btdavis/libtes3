#ifndef TES3SUBRECORD_H
#define TES3SUBRECORD_H

#include <optional>
#include "MemoryReader.h"

class TES3Subrecord
{
public:
	using Optional = std::optional<TES3Subrecord>;

	void read(MemoryReader& reader);
	MemoryReader data() const;

	uint32_t type() const;

private:
	MemoryReader m_reader;
	uint32_t m_type = 0;
};

#endif
