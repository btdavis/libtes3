#include "LAND.h"

LAND::LAND(const TES3Record& from)
{
	for (const auto& subrecord : from)
	{
		auto reader = subrecord.data();

		if (subrecord.type() == MakeRecordType('INTV'))
		{
			reader.read(m_cellX);
			reader.read(m_cellY);
		}
		else if (subrecord.type() == MakeRecordType('VNML'))
		{
			m_normals.resize(65 * 65);
			reader.read(m_normals.data(), m_normals.size());
		}
		else if (subrecord.type() == MakeRecordType('VHGT'))
		{
			reader.read(m_heightOffset);

			reader.seek(1); // unknown byte

			m_heightDeltas.resize(65 * 65);
			reader.read(m_heightDeltas.data(), m_heightDeltas.size());
		}
		else if (subrecord.type() == MakeRecordType('VCLR'))
		{
			m_colors.resize(65 * 65);
			reader.read(m_colors.data(), m_colors.size());
		}
		else if (subrecord.type() == MakeRecordType('VTEX'))
		{
			m_textureIndexes.resize(16 * 16);
			reader.read(m_textureIndexes.data(), m_textureIndexes.size());
		}
	}
}

int32_t LAND::cellX() const
{
	return m_cellX;
}

int32_t LAND::cellY() const
{
	return m_cellY;
}

float LAND::heightOffset() const
{
	return m_heightOffset;
}

int8_t LAND::heightDelta(int x, int y) const
{
	size_t index = y * 65 + x;

	if (m_heightDeltas.size() > index)
	{
		return m_heightDeltas[index];
	}
	else
	{
		return 0;
	}
}

LAND::Normal LAND::normal(int x, int y) const
{
	size_t index = y * 65 + x;

	if (m_normals.size() > index)
	{
		return m_normals[index];
	}
	else
	{
		return Normal();
	}
}

LAND::Color LAND::color(int x, int y) const
{
	size_t index = y * 65 + x;

	if (m_colors.size() > index)
	{
		return m_colors[index];
	}
	else
	{
		return Color();
	}
}

uint16_t LAND::textureIndex(int x, int y) const
{
	size_t index = y * 16 + x;

	if (m_textureIndexes.size() > index)
	{
		return m_textureIndexes[index];
	}
	else
	{
		return 0;
	}
}
