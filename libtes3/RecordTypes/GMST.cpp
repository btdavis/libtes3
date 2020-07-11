#include "GMST.h"

namespace libtes3
{

	GMST::GMST(const TES3Record& from)
		: TES3Record(from)
	{
		for (const auto& subrecord : from)
		{
			auto reader = subrecord.subrecordData();

			if (subrecord.subrecordType() == MakeRecordType('NAME'))
			{
				reader.readString(m_name);
			}
			else if (subrecord.subrecordType() == MakeRecordType('STRV'))
			{
				reader.readString(m_value);
			}
			else if (subrecord.subrecordType() == MakeRecordType('INTV'))
			{
				int32_t value;
				reader.read(value);
				m_value = std::to_string(value);
			}
			else if (subrecord.subrecordType() == MakeRecordType('FLTV'))
			{
				float value;
				reader.read(value);
				m_value = std::to_string(value);
			}
		}
	}

	std::string GMST::id() const
	{
		return std::string(name());
	}

	std::string_view GMST::name() const
	{
		return m_name;
	}

	std::string_view GMST::value() const
	{
		return m_value;
	}

}
