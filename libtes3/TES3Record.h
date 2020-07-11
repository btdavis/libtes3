#ifndef TES3RECORD_H
#define TES3RECORD_H

#include "TES3RecordType.h"
#include "TES3SubrecordIterator.h"
#include "TES3PluginReader.h"

#include <vector>
#include <optional>

namespace libtes3
{
	class TES3Plugin;

	class TES3Record
	{
	public:
		TES3Record(TES3PluginReader& reader);

		virtual std::string id() const;

		TES3Plugin *plugin() const;
		TES3PluginReader recordData() const;

		TES3SubrecordIterator begin() const;
		TES3SubrecordIterator end() const;

		TES3RecordType recordType() const;
		uint32_t recordHeader() const;
		uint32_t recordFlags() const;

	protected:
		TES3PluginReader m_reader;
		TES3RecordType m_type = 0;
		uint32_t m_header = 0;
		uint32_t m_flags = 0;
	};

}

#endif
