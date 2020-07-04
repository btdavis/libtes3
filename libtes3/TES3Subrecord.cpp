#include "pch.h"
#include "TES3Subrecord.h"

void TES3Subrecord::read(MemoryReader& reader)
{
	uint32_t size;

	reader.read(m_type);
	reader.read(size);

	m_reader = reader.spanNext(size);
	reader.seek(size);
}

MemoryReader TES3Subrecord::data() const
{
	return m_reader.spanAll();
}

uint32_t TES3Subrecord::type() const
{
	return m_type;
}
