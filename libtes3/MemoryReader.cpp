#include "MemoryReader.h"

MemoryReader::MemoryReader()
	: MemoryReader(nullptr, nullptr)
{

}

MemoryReader::MemoryReader(char* start, char* end)
	: m_start(start),
	m_end(end),
	m_cur(start)
{

}

MemoryReader::MemoryReader(char* start, size_t length)
	: MemoryReader(start, start + length)
{

}

MemoryReader MemoryReader::spanAll() const
{
	return span(0, size());
}

MemoryReader MemoryReader::spanNext(size_t length) const
{
	return span(pos(), length);
}

MemoryReader MemoryReader::span(size_t pos, size_t length) const
{
	return MemoryReader(m_start + pos, length);
}

bool MemoryReader::operator==(const MemoryReader& other) const
{
	if (eof() && other.eof())
	{
		return true;
	}

	return (m_start == other.m_start) && (m_end == other.m_end) && (m_cur == other.m_cur);
}

bool MemoryReader::operator!=(const MemoryReader& other) const
{
	return !(*this == other);
}

bool MemoryReader::readString(std::string& value)
{
	std::string_view temp;
	if (readString(temp))
	{
		value = temp;
		return true;
	}
	else
	{
		return false;
	}
}

bool MemoryReader::readString(std::string& value, size_t size)
{
	std::string_view temp;
	if (readString(temp, size))
	{
		value = temp;
		return true;
	}
	else
	{
		return false;
	}
}

bool MemoryReader::readString(std::string_view& value)
{
	if (m_cur < m_end)
	{
		char* strStart = m_cur;

		while (*m_cur && (m_cur < m_end))
		{
			m_cur++;
		}

		value = std::string_view(strStart, m_cur - strStart);

		return true;
	}
	else
	{
		return false;
	}
}

bool MemoryReader::readString(std::string_view& value, size_t size)
{
	if ((m_cur + size) < m_end)
	{
		value = std::string_view(m_cur, size);
		m_cur += size;

		return true;
	}
	else
	{
		return false;
	}
}

size_t MemoryReader::pos() const
{
	return (size_t)(m_cur - m_start);
}

size_t MemoryReader::size() const
{
	return (size_t)(m_end - m_start);
}

bool MemoryReader::eof() const
{
	return m_cur >= m_end;
}

void MemoryReader::seek(ptrdiff_t offset)
{
	if (((m_cur + offset) < m_end) && ((m_cur + offset) >= m_start))
	{
		m_cur += offset;
	}
}

void MemoryReader::setPos(size_t pos)
{
	if ((m_start + pos) < m_end)
	{
		m_cur = m_start + pos;
	}
}
