#include "GMST.h"

namespace libtes3
{

	GMST::GMST(const TES3Record& from)
	{
		for (const auto& subrecord : from)
		{
			auto reader = subrecord.data();

			if (subrecord.type() == MakeRecordType('NAME'))
			{
				reader.readString(m_name);
			}
			else if (subrecord.type() == MakeRecordType('STRV'))
			{
				reader.readString(m_value);
			}
			else if (subrecord.type() == MakeRecordType('INTV'))
			{
				int32_t value;
				reader.read(value);
				m_value = std::to_string(value);
			}
			else if (subrecord.type() == MakeRecordType('FLTV'))
			{
				float value;
				reader.read(value);
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

}
