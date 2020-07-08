#ifndef LIGH_H
#define LIGH_H

#include <string>

#include "../TES3Record.h"

namespace libtes3
{

	class LIGH
	{
	public:
		static constexpr TES3RecordType Type = MakeRecordType('LIGH');

		LIGH(const TES3Record& from);

		std::string_view name() const;
		std::string_view model() const;
		std::string_view friendlyName() const;
		std::string_view scriptName() const;

	private:
		std::string_view m_name;
		std::string_view m_model;
		std::string_view m_friendlyName;
		std::string_view m_scriptName;
	};

}

#endif
