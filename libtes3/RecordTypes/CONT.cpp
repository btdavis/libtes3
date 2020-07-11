#include "CONT.h"

namespace libtes3
{

	CONT::CONT(const TES3Record& from)
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
			else if (subrecord.subrecordType() == MakeRecordType('CNDT'))
			{
				reader.read(m_weight);
			}
			else if (subrecord.subrecordType() == MakeRecordType('FLAG'))
			{
				reader.read(m_flags);
			}
			else if (subrecord.subrecordType() == MakeRecordType('NPCO'))
			{
				Item item;
				reader.read(item.m_count);
				reader.readString(item.m_id);
				m_items.push_back(item);
			}
		}
	}

	std::string CONT::id() const
	{
		return std::string(name());
	}

	std::string_view CONT::name() const
	{
		return m_name;
	}

	std::string_view CONT::model() const
	{
		return m_model;
	}

	std::string_view CONT::friendlyName() const
	{
		return m_friendlyName;
	}

	float CONT::weight() const
	{
		return m_weight;
	}

	uint32_t CONT::flags() const
	{
		return m_flags;
	}

	const std::vector<CONT::Item>& CONT::items() const
	{
		return m_items;
	}

}
