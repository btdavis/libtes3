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

		CONT(const TES3Record& from);

		std::string_view name() const;
		std::string_view model() const;
		std::string_view friendlyName() const;

	private:
		std::string_view m_name;
		std::string_view m_model;
		std::string_view m_friendlyName;
	};

}

#endif
