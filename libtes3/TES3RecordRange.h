#ifndef TES3RECORDRANGE_H
#define TES3RECORDRANGE_H

#include "TES3RecordIterator.h"

class TES3RecordRange
{
public:
	TES3RecordRange(TES3RecordIterator begin, TES3RecordIterator end);

	TES3RecordIterator begin() const;
	TES3RecordIterator end() const;

private:
	TES3RecordIterator m_begin;
	TES3RecordIterator m_end;
};

#endif
