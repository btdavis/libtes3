#ifndef LAND_H
#define LAND_H

#include <string>

#include "../TES3Record.h"

class LAND
{
public:
	static constexpr TES3RecordType Type = MakeRecordType('LAND');

	LAND(const TES3Record& from);

	struct Vertex
	{
		struct
		{
			uint8_t x = 0;
			uint8_t y = 0;
			uint8_t z = 0;
		} normal;

		struct
		{
			uint8_t r = 0;
			uint8_t g = 0;
			uint8_t b = 0;
		} color;

		int8_t heightDelta;
	};

	int32_t cellX() const;
	int32_t cellY() const;
	float heightOffset() const;
	Vertex vertex(int x, int y) const;
	uint16_t textureIndex(int x, int y) const;

private:
	int32_t m_cellX = 0;
	int32_t m_cellY = 0;

	float m_heightOffset = 0.0f;
	std::vector<Vertex> m_vertices;
	std::vector<uint16_t> m_textureIndexes;
};

#endif
