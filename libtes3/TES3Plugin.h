#ifndef TES3FILE_H
#define TES3FILE_H

#include <vector>
#include "TES3Record.h"
#include "TES3RecordRange.h"
#include "TES3TypedRecordRange.h"

#include "RecordTypes/TES3.h"

namespace libtes3
{

	class TES3Plugin
	{
	public:
		TES3Plugin(const char* filename);

		std::string filename() const;
		std::string masterPlugin(int index) const;

		TES3PluginReader data() const;
		TES3RecordRange records() const;

		template<typename T>
		TES3TypedRecordRange<T> records() const
		{
			return TES3TypedRecordRange<T>(records());
		}

		template<typename T>
		std::optional<T> findRecord(const std::string& id) const
		{
			for (const auto& record : records<T>())
			{
				if (record.id() == id)
				{
					return record;
				}
			}

			return std::nullopt;
		}

	private:
		std::string m_filename;
		TES3PluginReader m_reader;
		std::vector<char> m_data;

		std::optional<TES3> m_header;
	};

}

#endif
