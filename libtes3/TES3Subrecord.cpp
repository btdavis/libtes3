#include "TES3Subrecord.h"

namespace libtes3
{

	TES3Subrecord::TES3Subrecord(MemoryReader& reader)
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

	TES3RecordType TES3Subrecord::type() const
	{
		return m_type;
	}

}
