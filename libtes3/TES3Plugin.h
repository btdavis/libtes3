#ifndef TES3FILE_H
#define TES3FILE_H

#include <vector>
#include "TES3RecordIterator.h"

class TES3Plugin
{
public:
	TES3Plugin(const char* filename);
	MemoryReader data();

	TES3RecordIterator begin() const;
	TES3RecordIterator end() const;

private:
	MemoryReader m_reader;
	std::vector<char> m_data;
};

#endif
