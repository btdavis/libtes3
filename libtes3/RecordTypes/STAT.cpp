#include "STAT.h"

namespace libtes3
{

	STAT::STAT(const TES3Record& from)
		: TES3Record(from)
	{
		for (const auto& subrecord : from)
		{
			auto reader = subrecord.subrecordData();

			if (subrecord.subrecordType() == MakeRecordType('NAME'))
			{
				reader.readString(m_name);
			}
			else if (subrecord.subrecordType() == MakeRecordType('MODL'))
			{
				reader.readString(m_model);
			}
		}
	}

	std::string STAT::id() const
	{
		return std::string(name());
	}

	std::string_view STAT::name() const
	{
		return m_name;
	}

	std::string_view STAT::model() const
	{
		return m_model;
	}

}
