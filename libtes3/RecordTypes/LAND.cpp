#include "LAND.h"

namespace libtes3
{

	LAND::LAND(const TES3Record& from)
		: TES3Record(from)
	{
		for (const auto& subrecord : from)
		{
			auto reader = subrecord.subrecordData();

			if (subrecord.subrecordType() == MakeRecordType('INTV'))
			{
				reader.read(m_cellX);
				reader.read(m_cellY);
			}
			else if (subrecord.subrecordType() == MakeRecordType('VNML'))
			{
				reader.read(m_normals, 65 * 65);
			}
			else if (subrecord.subrecordType() == MakeRecordType('VHGT'))
			{
				reader.read(m_heightOffset);
				reader.seek(1); // unknown byte
				reader.read(m_heightDeltas, 65 * 65);
			}
			else if (subrecord.subrecordType() == MakeRecordType('VCLR'))
			{
				reader.read(m_colors, 65 * 65);
			}
			else if (subrecord.subrecordType() == MakeRecordType('VTEX'))
			{
				reader.read(m_textureIndexes, 16 * 16);
			}
		}
	}

	std::string LAND::id() const
	{
		return "(" + std::to_string(cellX()) + "," + std::to_string(cellY()) + ")";
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

	float LAND::height(int x, int y) const
	{
		initHeights();

		size_t index = y * heightGridSize() + x;

		if (!m_heights.empty())
		{
			return m_heights[index];
		}
		else
		{
			return 0;
		}
	}

	int8_t LAND::heightDelta(int x, int y) const
	{
		size_t index = y * heightGridSize() + x;

		if (!m_heightDeltas.empty())
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
		size_t index = y * normalGridSize() + x;

		if (!m_normals.empty())
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
		size_t index = y * colorGridSize() + x;

		if (!m_colors.empty())
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
		size_t index = y * textureIndexGridSize() + x;

		if (!m_textureIndexes.empty())
		{
			return m_textureIndexes[index];
		}
		else
		{
			return 0;
		}
	}

	void LAND::initHeights() const
	{
		if (m_heights.empty() && !m_heightDeltas.empty())
		{
			m_heights.resize(m_heightDeltas.size());

			float yHeight = m_heightOffset;

			for (int y = 0; y < heightGridSize(); y++)
			{
				int index = y * heightGridSize();
				yHeight += m_heightDeltas[index];
				m_heights[index] = yHeight;

				float xHeight = yHeight;

				for (int x = 1; x < heightGridSize(); x++)
				{
					int xIndex = index + x;
					xHeight += m_heightDeltas[xIndex];
					m_heights[xIndex] = xHeight;
				}
			}
		}
	}
}
