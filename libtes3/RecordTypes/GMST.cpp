#include "GMST.h"

GMST::GMST(const TES3Record& from)
{
	for (const auto& subrecord : from)
	{
		if (subrecord.type() == MakeRecordType('NAME'))
		{
			subrecord.data().readString(m_name);
		}
		else if (subrecord.type() == MakeRecordType('STRV'))
		{
			subrecord.data().readString(m_value);
		}
		else if (subrecord.type() == MakeRecordType('INTV'))
		{
			int32_t value;
			subrecord.data().read(value);
			m_value = std::to_string(value);
		}
		else if (subrecord.type() == MakeRecordType('FLTV'))
		{
			float value;
			subrecord.data().read(value);
			m_value = std::to_string(value);
		}
	}
}

std::string GMST::name() const
{
	return m_name;
}

std::string GMST::value() const
{
	return m_value;
}
