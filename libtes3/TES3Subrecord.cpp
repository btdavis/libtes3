#include "TES3Subrecord.h"

namespace libtes3
{

	TES3Subrecord::TES3Subrecord(TES3PluginReader& reader)
	{
		uint32_t size;

		reader.read(m_type);
		reader.read(size);

		m_reader = reader.spanNext(size);
		reader.seek(size);
	}

	TES3Plugin* TES3Subrecord::plugin() const
	{
		return m_reader.plugin();
	}

	TES3PluginReader TES3Subrecord::subrecordData() const
	{
		return m_reader.spanAll();
	}

	TES3RecordType TES3Subrecord::subrecordType() const
	{
		return m_type;
	}

}
