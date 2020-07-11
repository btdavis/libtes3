#ifndef TES3READER_H
#define TES3READER_H

#include <string_view>
#include "nonstd_span.h"

namespace libtes3
{
	class TES3Plugin;

	class TES3PluginReader
	{
	public:
		TES3PluginReader();
		TES3PluginReader(TES3Plugin* plugin, char* start, char* end);
		TES3PluginReader(TES3Plugin* plugin, char* start, size_t length);

		TES3Plugin* plugin() const;

		TES3PluginReader spanAll() const; // equal to span(0, size())
		TES3PluginReader spanNext(size_t length) const; // equal to span(pos(), length)
		TES3PluginReader span(size_t pos, size_t length) const;

		bool operator==(const TES3PluginReader& other) const;
		bool operator!=(const TES3PluginReader& other) const;

		template<typename T>
		bool read(T& value)
		{
			return read(&value, 1);
		}

		template<typename T>
		bool read(T* buf, size_t length)
		{
			return readMemory((void*)buf, sizeof(T) * length);
		}

		template<typename T>
		bool read(nonstd::span<T>& value, size_t length)
		{
			if ((m_cur + length) < m_end)
			{
				value = nonstd::span((T*)m_cur, length);
				m_cur += value.size_bytes();

				return true;
			}
			else
			{
				return false;
			}
		}

		bool readMemory(void* buf, size_t size);

		bool readString(std::string& value);
		bool readString(std::string& value, size_t size);
		bool readString(std::string_view& value);
		bool readString(std::string_view& value, size_t size);

		size_t pos() const;
		size_t size() const;
		bool eof() const;
		void seek(ptrdiff_t offset);
		void setPos(size_t pos);

	private:
		TES3Plugin* m_plugin = nullptr;
		char* m_start = nullptr;
		char* m_end = nullptr;
		char* m_cur = nullptr;
	};

}

#endif
