#include "TES3PluginReader.h"
#include "TES3Plugin.h"

namespace libtes3
{

	TES3PluginReader::TES3PluginReader()
		: TES3PluginReader(nullptr, nullptr, nullptr)
	{

	}

	TES3PluginReader::TES3PluginReader(TES3Plugin* plugin, char* start, char* end)
		: m_plugin(plugin),
		m_start(start),
		m_end(end),
		m_cur(start)
	{

	}

	TES3PluginReader::TES3PluginReader(TES3Plugin* plugin, char* start, size_t length)
		: TES3PluginReader(plugin, start, start + length)
	{

	}

	TES3Plugin* TES3PluginReader::plugin() const
	{
		return m_plugin;
	}

	TES3PluginReader TES3PluginReader::spanAll() const
	{
		return span(0, size());
	}

	TES3PluginReader TES3PluginReader::spanNext(size_t length) const
	{
		return span(pos(), length);
	}

	TES3PluginReader TES3PluginReader::span(size_t pos, size_t length) const
	{
		return TES3PluginReader(m_plugin, m_start + pos, length);
	}

	bool TES3PluginReader::operator==(const TES3PluginReader& other) const
	{
		if (eof() && other.eof())
		{
			return true;
		}

		return (m_start == other.m_start) && (m_end == other.m_end) && (m_cur == other.m_cur);
	}

	bool TES3PluginReader::operator!=(const TES3PluginReader& other) const
	{
		return !(*this == other);
	}

	bool TES3PluginReader::readMemory(void* buf, size_t size)
	{
		if (m_cur + size <= m_end)
		{
			memcpy(buf, m_cur, size);
			m_cur += size;
			return true;
		}
		else
		{
			m_cur = m_end;
			return false;
		}
	}

	bool TES3PluginReader::readString(std::string& value)
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

	bool TES3PluginReader::readString(std::string& value, size_t size)
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

	bool TES3PluginReader::readString(std::string_view& value)
	{
		if (m_cur < m_end)
		{
			char* strStart = m_cur;

			while (*m_cur && (m_cur < m_end))
			{
				m_cur++;
			}

			value = std::string_view(strStart, m_cur - strStart);

			m_cur++;

			return true;
		}
		else
		{
			return false;
		}
	}

	bool TES3PluginReader::readString(std::string_view& value, size_t size)
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

	size_t TES3PluginReader::pos() const
	{
		return (size_t)(m_cur - m_start);
	}

	size_t TES3PluginReader::size() const
	{
		return (size_t)(m_end - m_start);
	}

	bool TES3PluginReader::eof() const
	{
		return m_cur >= m_end;
	}

	void TES3PluginReader::seek(ptrdiff_t offset)
	{
		if (((m_cur + offset) < m_end) && ((m_cur + offset) >= m_start))
		{
			m_cur += offset;
		}
	}

	void TES3PluginReader::setPos(size_t pos)
	{
		if ((m_start + pos) < m_end)
		{
			m_cur = m_start + pos;
		}
	}

}
