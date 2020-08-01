#include "LOCK.h"

namespace libtes3
{

	LOCK::LOCK(const TES3Record& from)
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
			else if (subrecord.subrecordType() == MakeRecordType('LKDT'))
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

	std::string LOCK::id() const
	{
		return std::string(name());
	}

	std::string_view LOCK::name() const
	{
		return m_name;
	}

	std::string_view LOCK::model() const
	{
		return m_model;
	}

	std::string_view LOCK::friendlyName() const
	{
		return m_friendlyName;
	}

	std::string_view LOCK::icon() const
	{
		return m_icon;
	}

	std::string_view LOCK::scriptName() const
	{
		return m_scriptName;
	}

	float LOCK::weight() const
	{
		return m_weight;
	}

	uint32_t LOCK::value() const
	{
		return m_value;
	}

	float LOCK::quality() const
	{
		return m_quality;
	}

	uint32_t LOCK::uses() const
	{
		return m_uses;
	}
}
