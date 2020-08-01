#include "APPA.h"

namespace libtes3
{

	APPA::APPA(const TES3Record& from)
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
			else if (subrecord.subrecordType() == MakeRecordType('AADT'))
			{
				reader.read(m_apparatusType);
				reader.read(m_quality);
				reader.read(m_weight);
				reader.read(m_value);
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

	std::string APPA::id() const
	{
		return std::string(name());
	}

	std::string_view APPA::name() const
	{
		return m_name;
	}

	std::string_view APPA::model() const
	{
		return m_model;
	}

	std::string_view APPA::friendlyName() const
	{
		return m_friendlyName;
	}

	std::string_view APPA::icon() const
	{
		return m_icon;
	}

	std::string_view APPA::scriptName() const
	{
		return m_scriptName;
	}

	float APPA::weight() const
	{
		return m_weight;
	}

	uint32_t APPA::value() const
	{
		return m_value;
	}

	float APPA::quality() const
	{
		return m_quality;
	}

	APPA::ApparatusType APPA::apparatusType() const
	{
		return m_apparatusType;
	}
}
