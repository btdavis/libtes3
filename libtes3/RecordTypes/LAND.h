#ifndef LAND_H
#define LAND_H

#include <string>

#include "../TES3Record.h"

class LAND
{
public:
	static constexpr TES3RecordType Type = MakeRecordType('LAND');

	LAND(const TES3Record& from);

#pragma pack(push)
#pragma pack(1)
	struct Normal
	{
		uint8_t x = 0;
		uint8_t y = 0;
		uint8_t z = 0;
	};

	struct Color
	{
		uint8_t x = 0;
		uint8_t y = 0;
		uint8_t z = 0;
	};
#pragma pack(pop)

	int32_t cellX() const;
	int32_t cellY() const;
	float heightOffset() const;
	int8_t heightDelta(int x, int y) const;
	Normal normal(int x, int y) const;
	Color color(int x, int y) const;
	uint16_t textureIndex(int x, int y) const;

private:
	int32_t m_cellX = 0;
	int32_t m_cellY = 0;

	float m_heightOffset = 0.0f;
	std::vector<int8_t> m_heightDeltas;
	std::vector<Normal> m_normals;
	std::vector<Color> m_colors;
	std::vector<uint16_t> m_textureIndexes;
};

#endif
