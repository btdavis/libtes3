#ifndef TES3TYPEDRECORDRANGE_H
#define TES3TYPEDRECORDRANGE_H

#include "TES3TypedRecordIterator.h"

namespace libtes3
{

	template<typename T>
	class TES3TypedRecordRange
	{
	public:
		TES3TypedRecordRange(TES3RecordRange range)
			: m_begin(range.begin()),
			m_end(range.end())
		{
		}

		TES3TypedRecordRange(TES3TypedRecordIterator<T> begin, TES3TypedRecordIterator<T> end)
			: m_begin(begin),
			m_end(end)
		{
		}

		TES3TypedRecordIterator<T> begin() const
		{
			return m_begin;
		}

		TES3TypedRecordIterator<T> end() const
		{
			return m_end;
		}

	private:
		TES3TypedRecordIterator<T> m_begin;
		TES3TypedRecordIterator<T> m_end;
	};

}

#endif
