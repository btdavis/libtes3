#include "pch.h"
#include "TES3Plugin.h"
#include "MemoryReader.h"

#include <fstream>

TES3Plugin::TES3Plugin(const char* filename)
{
	std::ifstream in = std::ifstream(filename, std::ios_base::binary | std::ios_base::in);
	in.seekg(0, std::ios_base::end);
	m_data.resize(in.tellg());
	in.seekg(0, std::ios_base::beg);
	in.read(m_data.data(), m_data.size());
	in.close();

	m_reader = MemoryReader(m_data.data(), m_data.size());
}

MemoryReader TES3Plugin::data()
{
	return m_reader;
}

TES3RecordIterator TES3Plugin::begin() const
{
	return TES3RecordIterator(m_reader.spanAll());
}

TES3RecordIterator TES3Plugin::end() const
{
	return TES3RecordIterator();
}
