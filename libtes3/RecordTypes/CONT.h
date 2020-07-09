#ifndef CONT_H
#define CONT_H

#include <string>

#include "../TES3Record.h"

namespace libtes3
{

	class CONT
	{
	public:
		static constexpr TES3RecordType Type = MakeRecordType('CONT');

		static constexpr uint32_t Flag_Organic = 0x01;
		static constexpr uint32_t Flag_Respawn = 0x02;
		static constexpr uint32_t Flag_Unknown = 0x08;

		struct Item
		{
			int32_t m_count = 0;
			std::string_view m_id;
		};

		CONT(const TES3Record& from);

		std::string_view name() const;
		std::string_view model() const;
		std::string_view friendlyName() const;
		float weight() const;
		uint32_t flags() const;
		const std::vector<Item>& items() const;

	private:
		std::string_view m_name;
		std::string_view m_model;
		std::string_view m_friendlyName;
		float m_weight = 0.0f;
		uint32_t m_flags = 0;
		std::vector<Item> m_items;
	};

}

#endif
