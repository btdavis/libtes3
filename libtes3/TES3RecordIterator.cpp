#include "pch.h"
#include "TES3RecordIterator.h"

TES3RecordIterator::TES3RecordIterator()
{

}

TES3RecordIterator::TES3RecordIterator(const MemoryReader& reader)
	: m_reader(reader)
{
	m_currentRecord.read(m_reader);
}

bool TES3RecordIterator::operator==(const TES3RecordIterator& other) const
{
	return m_reader == other.m_reader;
}

bool TES3RecordIterator::operator!=(const TES3RecordIterator& other) const
{
	return m_reader != other.m_reader;
}

TES3RecordIterator& TES3RecordIterator::operator++()
{
	m_currentRecord.read(m_reader);
	return *this;
}

TES3Record* TES3RecordIterator::operator*()
{
	return &m_currentRecord;
}

TES3Record* TES3RecordIterator::operator->()
{
	return &m_currentRecord;
}

const TES3Record* TES3RecordIterator::operator*() const
{
	return &m_currentRecord;
}

const TES3Record* TES3RecordIterator::operator->() const
{
	return &m_currentRecord;
}
