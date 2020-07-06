#include "LIGH.h"

LIGH::LIGH(const TES3Record& from)
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
		else if (subrecord.type() == MakeRecordType('SCPT'))
		{
			reader.readString(m_scriptName);
		}
	}
}

std::string LIGH::name() const
{
	return m_name;
}

std::string LIGH::model() const
{
	return m_model;
}

std::string LIGH::friendlyName() const
{
	return m_friendlyName;
}

std::string LIGH::scriptName() const
{
	return m_scriptName;
}
