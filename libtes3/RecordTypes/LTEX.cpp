#include "LTEX.h"

LTEX::LTEX(const TES3Record& from)
{
	for (const auto& subrecord : from)
	{
		auto reader = subrecord.data();

		if (subrecord.type() == MakeRecordType('NAME'))
		{
			reader.readString(m_name);
		}
		else if (subrecord.type() == MakeRecordType('INTV'))
		{
			reader.read(m_index);
		}
		else if (subrecord.type() == MakeRecordType('DATA'))
		{
			reader.readString(m_filename);
		}
	}
}

std::string LTEX::name() const
{
	return m_name;
}

int32_t LTEX::index() const
{
	return m_index;
}

std::string LTEX::filename() const
{
	return m_filename;
}
