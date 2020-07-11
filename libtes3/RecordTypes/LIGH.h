#ifndef LIGH_H
#define LIGH_H

#include <string>

#include "../TES3Record.h"

namespace libtes3
{

	class LIGH: public TES3Record
	{
	public:
		static constexpr TES3RecordType Type = MakeRecordType('LIGH');

		static constexpr uint32_t Flag_Dynamic = 0x0001;
		static constexpr uint32_t Flag_CanCarry = 0x0002;
		static constexpr uint32_t Flag_Negative = 0x0004;
		static constexpr uint32_t Flag_Flicker = 0x0008;
		static constexpr uint32_t Flag_Fire = 0x0010;
		static constexpr uint32_t Flag_DefaultOff = 0x0020;
		static constexpr uint32_t Flag_FlickerSlow = 0x0040;
		static constexpr uint32_t Flag_Pulse = 0x0080;
		static constexpr uint32_t Flag_PulseSlow = 0x0100;

#pragma pack(push)
#pragma pack(1)
		struct Color
		{
			uint8_t r = 0;
			uint8_t g = 0;
			uint8_t b = 0;
			uint8_t a = 0;
		};
#pragma pack(pop)

		LIGH(const TES3Record& from);

		virtual std::string id() const override;

		std::string_view name() const;
		std::string_view model() const;
		std::string_view friendlyName() const;
		std::string_view icon() const;
		std::string_view sound() const;
		std::string_view scriptName() const;
		float weight() const;
		uint32_t value() const;
		uint32_t time() const;
		uint32_t radius() const;
		Color color() const;
		uint32_t flags() const;

	private:
		std::string_view m_name;
		std::string_view m_model;
		std::string_view m_friendlyName;
		std::string_view m_icon;
		std::string_view m_sound;
		std::string_view m_scriptName;
		float m_weight = 0.0f;
		uint32_t m_value = 0;
		uint32_t m_time = 0;
		uint32_t m_radius = 0;
		Color m_color;
		uint32_t m_flags = 0;
	};

}

#endif
