#include "MISC.h"

namespace libtes3
{

	MISC::MISC(const TES3Record& from)
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
			else if (subrecord.subrecordType() == MakeRecordType('MCDT'))
			{
				reader.read(m_weight);
				reader.read(m_value);
			}
			else if (subrecord.subrecordType() == MakeRecordType('ITEX'))
			{
				reader.readString(m_icon);
			}
			else if (subrecord.subrecordType() == MakeRecordType('ENAM'))
			{
				reader.readString(m_enchantmentName);
			}
			else if (subrecord.subrecordType() == MakeRecordType('SCRI'))
			{
				reader.readString(m_scriptName);
			}
		}
	}

	std::string MISC::id() const
	{
		return std::string(name());
	}

	std::string_view MISC::name() const
	{
		return m_name;
	}

	std::string_view MISC::model() const
	{
		return m_model;
	}

	std::string_view MISC::friendlyName() const
	{
		return m_friendlyName;
	}

	std::string_view MISC::icon() const
	{
		return m_icon;
	}

	std::string_view MISC::enchantmentName() const
	{
		return m_enchantmentName;
	}

	std::string_view MISC::scriptName() const
	{
		return m_scriptName;
	}

	float MISC::weight() const
	{
		return m_weight;
	}

	uint32_t MISC::value() const
	{
		return m_value;
	}
}
