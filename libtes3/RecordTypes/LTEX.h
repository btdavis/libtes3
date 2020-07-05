#ifndef LTEX_H
#define LTEX_H

#include <string>

#include "../TES3Record.h"

class LTEX
{
public:
	static constexpr TES3RecordType Type = MakeRecordType('LTEX');

	LTEX(const TES3Record& from);

	std::string name() const;
	int32_t index() const;
	std::string filename() const;

private:
	std::string m_name;
	int32_t m_index = 0;
	std::string m_filename;
};

#endif
