#include "PROB.h"

namespace libtes3
{

	PROB::PROB(const TES3Record& from)
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
			else if (subrecord.subrecordType() == MakeRecordType('PBDT'))
			{
				reader.read(m_weight);
				reader.read(m_value);
				reader.read(m_quality);
				reader.read(m_uses);
			}
			else if (subrecord.subrecordType() == MakeRecordType('ITEX'))
			{
				reader.readString(m_icon);
			}
			else if (subrecord.subrecordType() == MakeRecordType('SCRI'))
			{
				reader.readString(m_scriptName);
			}
		}
	}

	std::string PROB::id() const
	{
		return std::string(name());
	}

	std::string_view PROB::name() const
	{
		return m_name;
	}

	std::string_view PROB::model() const
	{
		return m_model;
	}

	std::string_view PROB::friendlyName() const
	{
		return m_friendlyName;
	}

	std::string_view PROB::icon() const
	{
		return m_icon;
	}

	std::string_view PROB::scriptName() const
	{
		return m_scriptName;
	}

	float PROB::weight() const
	{
		return m_weight;
	}

	uint32_t PROB::value() const
	{
		return m_value;
	}

	float PROB::quality() const
	{
		return m_quality;
	}

	uint32_t PROB::uses() const
	{
		return m_uses;
	}
}
