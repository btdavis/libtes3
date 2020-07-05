#include "STAT.h"

STAT::STAT(const TES3Record& from)
{
	for (const auto& subrecord : from)
	{
		auto reader = subrecord.data();

		if (subrecord.type() == MakeRecordType('NAME'))
		{
			reader.readString(m_name);
		}
		else if (subrecord.type() == MakeRecordType('MODL'))
		{
			reader.readString(m_filename);
		}
	}
}

std::string STAT::name() const
{
	return m_name;
}

std::string STAT::filename() const
{
	return m_filename;
}
