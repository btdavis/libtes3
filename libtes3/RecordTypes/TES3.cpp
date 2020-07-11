#include "TES3.h"

namespace libtes3
{

	TES3::TES3(const TES3Record& from)
		: TES3Record(from)
	{
		for (const auto& subrecord : from)
		{
			auto reader = subrecord.subrecordData();

			if (subrecord.subrecordType() == MakeRecordType('HEDR'))
			{
				reader.read(m_version);
				int32_t unknown;
				reader.read(unknown);
				reader.readString(m_company, 32);
				reader.readString(m_description, 256);
				reader.read(m_countRecords);

				m_company = m_company.substr(0, strnlen(m_company.data(), m_company.size())); // trim to null terminator
				m_description = m_description.substr(0, strnlen(m_description.data(), m_description.size())); // trim to null terminator
			}
			else if (subrecord.subrecordType() == MakeRecordType('MAST'))
			{
				MasterPlugin toAdd;
				reader.readString(toAdd.name);
				m_masterPlugins.push_back(toAdd);
			}
			else if (subrecord.subrecordType() == MakeRecordType('DATA'))
			{
				if (!m_masterPlugins.empty())
				{
					reader.read(m_masterPlugins.back().size);
				}
			}
		}
	}

	std::string TES3::id() const
	{
		return "";
	}

	float TES3::version() const
	{
		return m_version;
	}

	std::string_view TES3::company() const
	{
		return m_company;
	}

	std::string_view TES3::description() const
	{
		return m_description;
	}

	uint32_t TES3::countRecords() const
	{
		return m_countRecords;
	}

	const std::vector<TES3::MasterPlugin>& TES3::masterPlugins() const
	{
		return m_masterPlugins;
	}
}
