#include "TES3RecordRange.h"

namespace libtes3
{

	TES3RecordRange::TES3RecordRange(TES3RecordIterator begin, TES3RecordIterator end)
		: m_begin(begin), m_end(end)
	{
	}

	TES3RecordIterator TES3RecordRange::begin() const
	{
		return m_begin;
	}

	TES3RecordIterator TES3RecordRange::end() const
	{
		return m_end;
	}

}
