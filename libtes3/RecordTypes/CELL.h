#ifndef CELL_H
#define CELL_H

#include <string>
#include <vector>

#include "../TES3Record.h"
#include "CELLRef.h"

namespace libtes3
{

	class CELL
	{
	public:
		static constexpr TES3RecordType Type = MakeRecordType('CELL');

		static constexpr uint32_t FlagInterior = 0x01;
		static constexpr uint32_t FlagHasWater = 0x02;
		static constexpr uint32_t FlagNoSleep = 0x04;
		static constexpr uint32_t FlagInteriorWeather = 0x08;

		CELL(const TES3Record& from);

		std::string_view name() const;
		std::string_view region() const;

		int32_t cellX() const;
		int32_t cellY() const;
		uint32_t flags() const;

		const std::vector<CELLRef>& references() const;

	private:
		std::string_view m_name;
		std::string_view m_region;

		int32_t m_cellX = 0;
		int32_t m_cellY = 0;
		uint32_t m_flags = 0;

		float m_waterHeight = 0.0f;

		uint32_t m_ambientColor = 0;
		uint32_t m_sunlightColor = 0;
		uint32_t m_fogColor = 0;
		float m_fogDensity = 0.0f;

		std::vector<CELLRef> m_references;
	};

}

#endif
