#include "LTEX.h"

LTEX::LTEX(const TES3Record& from)
{
	for (const auto& subrecord : from)
	{
		if (subrecord.type() == MakeRecordType('NAME'))
		{
			subrecord.data().readString(m_name);
		}
		else if (subrecord.type() == MakeRecordType('INTV'))
		{
			subrecord.data().read(m_index);
		}
		else if (subrecord.type() == MakeRecordType('DATA'))
		{
			subrecord.data().readString(m_filename);
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
