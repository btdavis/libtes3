#include "TES3Record.h"
#include "TES3Plugin.h"

namespace libtes3
{

	TES3Record::TES3Record(TES3PluginReader& reader)
	{
		uint32_t size;

		reader.read(m_type);
		reader.read(size);
		reader.read(m_header);
		reader.read(m_flags);

		m_reader = reader.spanNext(size);
		reader.seek(size);
	}

	std::string TES3Record::id() const
	{
		return "";
	}

	TES3Plugin *TES3Record::plugin() const
	{
		return m_reader.plugin();
	}

	TES3PluginReader TES3Record::recordData() const
	{
		return m_reader.spanAll();
	}

	TES3SubrecordIterator TES3Record::begin() const
	{
		return TES3SubrecordIterator(m_reader.spanAll());
	}

	TES3SubrecordIterator TES3Record::end() const
	{
		return TES3SubrecordIterator();
	}

	TES3RecordType TES3Record::recordType() const
	{
		return m_type;
	}

	uint32_t TES3Record::recordHeader() const
	{
		return m_header;
	}

	uint32_t TES3Record::recordFlags() const
	{
		return m_flags;
	}

}
