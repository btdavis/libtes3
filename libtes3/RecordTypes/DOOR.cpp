#include "DOOR.h"

namespace libtes3
{

	DOOR::DOOR(const TES3Record& from)
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
				reader.readString(m_model);
			}
			else if (subrecord.type() == MakeRecordType('FNAM'))
			{
				reader.readString(m_friendlyName);
			}
			else if (subrecord.type() == MakeRecordType('SCIP'))
			{
				reader.readString(m_scriptName);
			}
		}
	}

	std::string DOOR::name() const
	{
		return m_name;
	}

	std::string DOOR::model() const
	{
		return m_model;
	}

	std::string DOOR::friendlyName() const
	{
		return m_friendlyName;
	}

	std::string DOOR::scriptName() const
	{
		return m_scriptName;
	}

}
