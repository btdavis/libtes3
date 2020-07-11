#include "TES3RecordIterator.h"

namespace libtes3
{

	TES3RecordIterator::TES3RecordIterator()
	{

	}

	TES3RecordIterator::TES3RecordIterator(const TES3PluginReader& reader)
		: m_reader(reader)
	{
		if (!m_reader.eof())
		{
			m_currentRecord = TES3Record(m_reader);
		}
	}

	bool TES3RecordIterator::isValid() const
	{
		return m_currentRecord.has_value();
	}

	bool TES3RecordIterator::operator==(const TES3RecordIterator& other) const
	{
		if (!isValid() && !other.isValid())
		{
			return true;
		}

		return m_reader == other.m_reader;
	}

	bool TES3RecordIterator::operator!=(const TES3RecordIterator& other) const
	{
		return !(*this == other);
	}

	TES3RecordIterator& TES3RecordIterator::operator++()
	{
		if (m_reader.eof())
		{
			m_currentRecord = std::nullopt;
		}
		else
		{
			m_currentRecord = TES3Record(m_reader);
		}

		return *this;
	}

	TES3Record& TES3RecordIterator::operator*()
	{
		return m_currentRecord.value();
	}

	const TES3Record& TES3RecordIterator::operator*() const
	{
		return m_currentRecord.value();
	}

	TES3Record* TES3RecordIterator::operator->()
	{
		return &m_currentRecord.value();
	}

	const TES3Record* TES3RecordIterator::operator->() const
	{
		return &m_currentRecord.value();
	}

}
