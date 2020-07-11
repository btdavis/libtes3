#ifndef TES3TYPEDRECORDITERATOR_H
#define TES3TYPEDRECORDITERATOR_H

#include "TES3RecordIterator.h"

#include <optional>

namespace libtes3
{

	template<typename T>
	class TES3TypedRecordIterator
	{
	public:
		TES3TypedRecordIterator(TES3RecordIterator base)
			: m_base(base)
		{
			while (m_base.isValid() && (m_base->recordType() != T::Type))
			{
				++m_base;
			}

			if (m_base.isValid())
			{
				m_currentValue = T(*m_base);
			}
		}

		bool isValid() const
		{
			return m_currentValue.has_value();
		}

		bool operator==(const TES3TypedRecordIterator<T>& other) const
		{
			return m_base == other.m_base;
		}

		bool operator!=(const TES3TypedRecordIterator<T>& other) const
		{
			return !(*this == other);
		}

		TES3TypedRecordIterator<T>& operator++()
		{
			++m_base;

			while (m_base.isValid() && (m_base->recordType() != T::Type))
			{
				++m_base;
			}

			if (m_base.isValid())
			{
				m_currentValue = T(*m_base);
			}
			else
			{
				m_currentValue = std::nullopt;
			}

			return *this;
		}

		T& operator*()
		{
			return m_currentValue.value();
		}

		const T& operator*() const
		{
			return m_currentValue.value();
		}

		T* operator->()
		{
			return &m_currentValue.value();
		}

		const T* operator->() const
		{
			return &m_currentValue.value();
		}

	private:
		TES3RecordIterator m_base;
		std::optional<T> m_currentValue = std::nullopt;
	};

}

#endif
