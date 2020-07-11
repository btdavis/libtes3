#include "GLOB.h"

namespace libtes3
{

	GLOB::GLOB(const TES3Record& from)
		: TES3Record(from)
	{
		for (const auto& subrecord : from)
		{
			auto reader = subrecord.subrecordData();

			if (subrecord.subrecordType() == MakeRecordType('NAME'))
			{
				reader.readString(m_name);
			}
			else if (subrecord.subrecordType() == MakeRecordType('FNAM'))
			{
				char value;
				reader.read(value);

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
			else if (subrecord.subrecordType() == MakeRecordType('FLTV'))
			{
				reader.read(m_value);
			}
		}
	}

	std::string GLOB::id() const
	{
		return std::string(name());
	}

	std::string_view GLOB::name() const
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

}
