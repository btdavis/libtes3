#ifndef MISC_H
#define MISC_H

#include <string>

#include "../TES3Record.h"

namespace libtes3
{

	class MISC: public TES3Record
	{
	public:
		static constexpr TES3RecordType Type = MakeRecordType('MISC');

		MISC(const TES3Record& from);

		virtual std::string id() const override;

		std::string_view name() const;
		std::string_view model() const;
		std::string_view friendlyName() const;
		std::string_view icon() const;
		std::string_view enchantmentName() const;
		std::string_view scriptName() const;
		float weight() const;
		uint32_t value() const;

	private:
		std::string_view m_name;
		std::string_view m_model;
		std::string_view m_friendlyName;
		std::string_view m_icon;
		std::string_view m_enchantmentName;
		std::string_view m_scriptName;
		float m_weight = 0.0f;
		uint32_t m_value = 0;
	};

}

#endif
