#include "DOOR.h"

namespace libtes3
{

	DOOR::DOOR(const TES3Record& from)
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
			else if (subrecord.subrecordType() == MakeRecordType('FNAM'))
			{
				reader.readString(m_friendlyName);
			}
			else if (subrecord.subrecordType() == MakeRecordType('SCIP'))
			{
				reader.readString(m_scriptName);
			}
			else if (subrecord.subrecordType() == MakeRecordType('SNAM'))
			{
				reader.readString(m_soundOpen);
			}
			else if (subrecord.subrecordType() == MakeRecordType('ANAM'))
			{
				reader.readString(m_soundClose);
			}
		}
	}

	std::string DOOR::id() const
	{
		return std::string(name());
	}

	std::string_view DOOR::name() const
	{
		return m_name;
	}

	std::string_view DOOR::model() const
	{
		return m_model;
	}

	std::string_view DOOR::friendlyName() const
	{
		return m_friendlyName;
	}

	std::string_view DOOR::scriptName() const
	{
		return m_scriptName;
	}

	std::string_view DOOR::soundOpen() const
	{
		return m_soundOpen;
	}

	std::string_view DOOR::soundClose() const
	{
		return m_soundClose;
	}

}
