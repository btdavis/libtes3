#ifndef SCPT_H
#define SCPT_H

#include <string>

#include "../TES3Record.h"

namespace libtes3
{

	class SCPT
	{
	public:
		static constexpr TES3RecordType Type = MakeRecordType('SCPT');

		SCPT(const TES3Record& from);

		std::string_view name() const;
		std::vector<std::string_view> locals() const;
		std::string_view script() const;

	private:
		std::string_view m_name;
		std::vector<std::string_view> m_locals;
		std::string_view m_script;
	};

}

#endif
