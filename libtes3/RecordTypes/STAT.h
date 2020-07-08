#ifndef STAT_H
#define STAT_H

#include <string>

#include "../TES3Record.h"

namespace libtes3
{

	class STAT
	{
	public:
		static constexpr TES3RecordType Type = MakeRecordType('STAT');

		STAT(const TES3Record& from);

		std::string_view name() const;
		std::string_view model() const;

	private:
		std::string_view m_name;
		std::string_view m_model;
	};

}

#endif
