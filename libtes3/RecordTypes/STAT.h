#ifndef STAT_H
#define STAT_H

#include <string>

#include "../TES3Record.h"

class STAT
{
public:
	static constexpr TES3RecordType Type = MakeRecordType('STAT');

	STAT(const TES3Record& from);

	std::string name() const;
	std::string model() const;

private:
	std::string m_name;
	std::string m_model;
};

#endif
