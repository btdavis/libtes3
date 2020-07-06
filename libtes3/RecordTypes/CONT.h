#ifndef CONT_H
#define CONT_H

#include <string>

#include "../TES3Record.h"

class CONT
{
public:
	static constexpr TES3RecordType Type = MakeRecordType('CONT');

	CONT(const TES3Record& from);

	std::string name() const;
	std::string model() const;
	std::string friendlyName() const;

private:
	std::string m_name;
	std::string m_model;
	std::string m_friendlyName;
};

#endif
