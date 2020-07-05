#include "GLOB.h"

GLOB::GLOB(const TES3Record& from)
{
	for (const auto& subrecord : from)
	{
		if (subrecord.type() == MakeRecordType('NAME'))
		{
			subrecord.data().readString(m_name);
		}
		else if (subrecord.type() == MakeRecordType('FNAM'))
		{
			char value;
			subrecord.data().read(value);

			switch (value)
			{
			case 's':
				m_valueType = ValueType::Short;
				break;
			case 'l':
				m_valueType = ValueType::Long;
				break;
			case 'f':
				m_valueType = ValueType::Float;
				break;
			default:
				m_valueType = ValueType::Unknown;
				break;
			}
		}
		else if (subrecord.type() == MakeRecordType('FLTV'))
		{
			subrecord.data().read(m_value);
		}
	}
}

std::string GLOB::name() const
{
	return m_name;
}

GLOB::ValueType GLOB::valueType() const
{
	return m_valueType;
}

float GLOB::value() const
{
	return m_value;
}
