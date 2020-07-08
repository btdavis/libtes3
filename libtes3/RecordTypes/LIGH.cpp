#include "LIGH.h"

namespace libtes3
{

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

	std::string_view LIGH::name() const
	{
		return m_name;
	}

	std::string_view LIGH::model() const
	{
		return m_model;
	}

	std::string_view LIGH::friendlyName() const
	{
		return m_friendlyName;
	}

	std::string_view LIGH::scriptName() const
	{
		return m_scriptName;
	}

}
