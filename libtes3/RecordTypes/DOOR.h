#ifndef DOOR_H
#define DOOR_H

#include <string>

#include "../TES3Record.h"

namespace libtes3
{

	class DOOR
	{
	public:
		static constexpr TES3RecordType Type = MakeRecordType('DOOR');

		DOOR(const TES3Record& from);

		std::string_view name() const;
		std::string_view model() const;
		std::string_view friendlyName() const;
		std::string_view scriptName() const;
		std::string_view soundOpen() const;
		std::string_view soundClose() const;

	private:
		std::string_view m_name;
		std::string_view m_model;
		std::string_view m_friendlyName;
		std::string_view m_scriptName;
		std::string_view m_soundOpen;
		std::string_view m_soundClose;
	};

}

#endif
