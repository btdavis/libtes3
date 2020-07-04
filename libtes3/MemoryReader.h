#ifndef TES3READER_H
#define TES3READER_H

#include <string_view>

class MemoryReader
{
public:
	MemoryReader();
	MemoryReader(char* start, char* end);
	MemoryReader(char* start, size_t length);

	MemoryReader spanAll() const; // equal to span(0, size())
	MemoryReader spanNext(size_t length) const; // equal to span(pos(), length)
	MemoryReader span(size_t pos, size_t length) const;

	bool operator==(const MemoryReader& other) const;
	bool operator!=(const MemoryReader& other) const;

	template<typename T>
	bool read(T& value)
	{
		if (m_cur + sizeof(value) <= m_end)
		{
			value = *(T*)m_cur;
			m_cur += sizeof(value);
			return true;
		}
		else
		{
			m_cur = m_end;
			return false;
		}
	}

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
	char* m_start = nullptr;
	char* m_end = nullptr;
	char* m_cur = nullptr;
};

#endif
