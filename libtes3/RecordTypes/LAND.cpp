#include "LAND.h"

LAND::LAND(const TES3Record& from)
{
	m_vertices.resize(65 * 65);
	m_textureIndexes.resize(16 * 16);
	
	for (const auto& subrecord : from)
	{
		if (subrecord.type() == MakeRecordType('INTV'))
		{
			subrecord.data().read(m_cellX);
			subrecord.data().read(m_cellY);
		}
		else if (subrecord.type() == MakeRecordType('VNML'))
		{
			for (size_t i = 0; i < m_vertices.size(); i++)
			{
				subrecord.data().read(m_vertices[i].normal.x);
				subrecord.data().read(m_vertices[i].normal.y);
				subrecord.data().read(m_vertices[i].normal.z);
			}
		}
		else if (subrecord.type() == MakeRecordType('VHGT'))
		{
			subrecord.data().read(m_heightOffset);

			subrecord.data().seek(1); // unknown byte

			for (size_t i = 0; i < m_vertices.size(); i++)
			{
				subrecord.data().read(m_vertices[i].heightDelta);
			}
		}
		else if (subrecord.type() == MakeRecordType('VCLR'))
		{
			for (size_t i = 0; i < m_vertices.size(); i++)
			{
				subrecord.data().read(m_vertices[i].color.r);
				subrecord.data().read(m_vertices[i].color.g);
				subrecord.data().read(m_vertices[i].color.b);
			}
		}
		else if (subrecord.type() == MakeRecordType('VTEX'))
		{
			for (size_t i = 0; i < m_textureIndexes.size(); i++)
			{
				subrecord.data().read(m_textureIndexes[i]);
			}
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

LAND::Vertex LAND::vertex(int x, int y) const
{
	if (!m_vertices.empty())
	{
		return m_vertices[y * 65 + x];
	}
}

uint16_t LAND::textureIndex(int x, int y) const
{
	if (!m_textureIndexes.empty())
	{
		return m_textureIndexes[y * 16 + x];
	}
}
