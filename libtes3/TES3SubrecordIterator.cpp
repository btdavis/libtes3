#include "TES3SubrecordIterator.h"

namespace libtes3
{

	TES3SubrecordIterator::TES3SubrecordIterator()
	{

	}

	TES3SubrecordIterator::TES3SubrecordIterator(const TES3PluginReader& reader)
		: m_reader(reader)
	{
		if (!m_reader.eof())
		{
			m_currentSubrecord = TES3Subrecord(m_reader);
		}
	}

	bool TES3SubrecordIterator::isValid() const
	{
		return m_currentSubrecord.has_value();
	}

	bool TES3SubrecordIterator::operator==(const TES3SubrecordIterator& other) const
	{
		if (!isValid() && !other.isValid())
		{
			return true;
		}

		return m_reader == other.m_reader;
	}

	bool TES3SubrecordIterator::operator!=(const TES3SubrecordIterator& other) const
	{
		return !(*this == other);
	}

	TES3SubrecordIterator& TES3SubrecordIterator::operator++()
	{
		if (m_reader.eof())
		{
			m_currentSubrecord = std::nullopt;
		}
		else
		{
			m_currentSubrecord = TES3Subrecord(m_reader);
		}

		return *this;
	}

	TES3Subrecord& TES3SubrecordIterator::operator*()
	{
		return m_currentSubrecord.value();
	}

	const TES3Subrecord& TES3SubrecordIterator::operator*() const
	{
		return m_currentSubrecord.value();
	}

	TES3Subrecord* TES3SubrecordIterator::operator->()
	{
		return &m_currentSubrecord.value();
	}

	const TES3Subrecord* TES3SubrecordIterator::operator->() const
	{
		return &m_currentSubrecord.value();
	}

}
