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

		std::string name() const;
		std::string model() const;
		std::string friendlyName() const;
		std::string scriptName() const;

	private:
		std::string m_name;
		std::string m_model;
		std::string m_friendlyName;
		std::string m_scriptName;
	};

}

#endif
