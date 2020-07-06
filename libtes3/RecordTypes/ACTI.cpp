#include "ACTI.h"

ACTI::ACTI(const TES3Record& from)
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
		else if (subrecord.type() == MakeRecordType('SCRI'))
		{
			reader.readString(m_scriptName);
		}
	}
}

std::string ACTI::name() const
{
	return m_name;
}

std::string ACTI::model() const
{
	return m_model;
}

std::string ACTI::friendlyName() const
{
	return m_friendlyName;
}

std::string ACTI::scriptName() const
{
	return m_scriptName;
}
