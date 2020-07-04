#include "pch.h"
#include "TES3SubrecordIterator.h"

TES3SubrecordIterator::TES3SubrecordIterator()
{

}

TES3SubrecordIterator::TES3SubrecordIterator(const MemoryReader& reader)
	: m_reader(reader)
{
	m_currentSubrecord.read(m_reader);
}

bool TES3SubrecordIterator::operator==(const TES3SubrecordIterator& other) const
{
	return m_reader == other.m_reader;
}

bool TES3SubrecordIterator::operator!=(const TES3SubrecordIterator& other) const
{
	return m_reader != other.m_reader;
}

TES3SubrecordIterator& TES3SubrecordIterator::operator++()
{
	m_currentSubrecord.read(m_reader);
	return *this;
}

TES3Subrecord* TES3SubrecordIterator::operator*()
{
	return &m_currentSubrecord;
}

TES3Subrecord* TES3SubrecordIterator::operator->()
{
	return &m_currentSubrecord;
}

const TES3Subrecord* TES3SubrecordIterator::operator*() const
{
	return &m_currentSubrecord;
}

const TES3Subrecord* TES3SubrecordIterator::operator->() const
{
	return &m_currentSubrecord;
}
