#include "LIGH.h"

namespace libtes3
{

	LIGH::LIGH(const TES3Record& from)
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
			else if (subrecord.subrecordType() == MakeRecordType('SCPT'))
			{
				reader.readString(m_scriptName);
			}
			else if (subrecord.subrecordType() == MakeRecordType('LHDT'))
			{
				reader.read(m_weight);
				reader.read(m_value);
				reader.read(m_time);
				reader.read(m_radius);
				reader.read(m_color);
				reader.read(m_flags);
			}
			else if (subrecord.subrecordType() == MakeRecordType('ITEX'))
			{
				reader.readString(m_icon);
			}
			else if (subrecord.subrecordType() == MakeRecordType('SNAM'))
			{
				reader.readString(m_sound);
			}
		}
	}

	std::string LIGH::id() const
	{
		return std::string(name());
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

	std::string_view LIGH::icon() const
	{
		return m_icon;
	}

	std::string_view LIGH::sound() const
	{
		return m_sound;
	}

	std::string_view LIGH::scriptName() const
	{
		return m_scriptName;
	}

	float LIGH::weight() const
	{
		return m_weight;
	}

	uint32_t LIGH::value() const
	{
		return m_value;
	}

	uint32_t LIGH::time() const
	{
		return m_time;
	}

	uint32_t LIGH::radius() const
	{
		return m_radius;
	}

	LIGH::Color LIGH::color() const
	{
		return m_color;
	}

	uint32_t LIGH::flags() const
	{
		return m_flags;
	}
}
