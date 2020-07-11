#include "ACTI.h"

namespace libtes3
{

	ACTI::ACTI(const TES3Record& from)
		: TES3Record(from)
	{
		for (const auto& subrecord : *this)
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
			else if (subrecord.subrecordType() == MakeRecordType('FNAM'))
			{
				reader.readString(m_friendlyName);
			}
			else if (subrecord.subrecordType() == MakeRecordType('SCRI'))
			{
				reader.readString(m_scriptName);
			}
		}
	}

	std::string ACTI::id() const
	{
		return std::string(name());
	}

	std::string_view ACTI::name() const
	{
		return m_name;
	}

	std::string_view ACTI::model() const
	{
		return m_model;
	}

	std::string_view ACTI::friendlyName() const
	{
		return m_friendlyName;
	}

	std::string_view ACTI::scriptName() const
	{
		return m_scriptName;
	}

}
