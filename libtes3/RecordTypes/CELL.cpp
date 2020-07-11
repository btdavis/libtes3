#include "CELL.h"

namespace libtes3
{

	CELL::CELL(const TES3Record& from)
	{
		for (const auto& subrecord : from)
		{
			auto reader = subrecord.data();

			if (subrecord.type() == MakeRecordType('FRMR'))
			{
				m_references.push_back(CELLRef());
				m_references.back().addSubrecord(subrecord);
			}
			else if (!m_references.empty())
			{
				m_references.back().addSubrecord(subrecord);
			}
			else if (subrecord.type() == MakeRecordType('NAME'))
			{
				reader.readString(m_name);
			}
			else if (subrecord.type() == MakeRecordType('DATA'))
			{
				reader.read(m_flags);
				reader.read(m_cellX);
				reader.read(m_cellY);
			}
			else if (subrecord.type() == MakeRecordType('RGNN'))
			{
				reader.readString(m_region);
			}
			else if (subrecord.type() == MakeRecordType('WHGT'))
			{
				reader.read(m_waterHeight);
			}
			else if (subrecord.type() == MakeRecordType('AMBI'))
			{
				reader.read(m_ambientColor);
				reader.read(m_sunlightColor);
				reader.read(m_fogColor);
				reader.read(m_fogDensity);
			}
		}
	}

	std::string_view CELL::name() const
	{
		return m_name;
	}

	std::string_view CELL::region() const
	{
		return m_region;
	}

	int32_t CELL::cellX() const
	{
		return m_cellX;
	}

	int32_t CELL::cellY() const
	{
		return m_cellY;
	}

	uint32_t CELL::flags() const
	{
		return m_flags;
	}

	float CELL::waterHeight() const
	{
		return m_waterHeight;
	}

	CELL::Color CELL::ambientColor() const
	{
		return m_ambientColor;
	}

	CELL::Color CELL::sunlightColor() const
	{
		return m_sunlightColor;
	}

	CELL::Color CELL::fogColor() const
	{
		return m_fogColor;
	}

	float CELL::fogDensity() const
	{
		return m_fogDensity;
	}

	const std::vector<CELLRef>& CELL::references() const
	{
		return m_references;
	}

}
