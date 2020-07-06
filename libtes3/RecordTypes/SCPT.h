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

		std::string name() const;
		std::vector<std::string> locals() const;
		std::string script() const;

	private:
		std::string m_name;
		std::vector<std::string> m_locals;
		std::string m_script;
	};

}

#endif
