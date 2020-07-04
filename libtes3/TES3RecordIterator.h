#ifndef TES3RECORDITERATOR_H
#define TES3RECORDITERATOR_H

#include "TES3Record.h"

class TES3RecordIterator
{
public:
	TES3RecordIterator();
	TES3RecordIterator(const MemoryReader& reader);

	bool operator==(const TES3RecordIterator& other) const;
	bool operator!=(const TES3RecordIterator& other) const;

	TES3RecordIterator& operator++();

	TES3Record* operator*();
	TES3Record* operator->();
	const TES3Record* operator*() const;
	const TES3Record* operator->() const;

private:
	MemoryReader m_reader;
	TES3Record m_currentRecord;
};

#endif
