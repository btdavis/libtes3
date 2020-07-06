#include "TES3Plugin.h"
#include "MemoryReader.h"

#include <fstream>

namespace libtes3
{

	TES3Plugin::TES3Plugin(const char* filename)
	{
		std::ifstream in = std::ifstream(filename, std::ios_base::binary | std::ios_base::in);
		in.seekg(0, std::ios_base::end);
		m_data.resize((size_t)in.tellg());
		in.seekg(0, std::ios_base::beg);
		in.read(m_data.data(), m_data.size());
		in.close();

		m_reader = MemoryReader(m_data.data(), m_data.size());
	}

	MemoryReader TES3Plugin::data()
	{
		return m_reader;
	}

	TES3RecordRange TES3Plugin::records() const
	{
		return TES3RecordRange(TES3RecordIterator(m_reader.spanAll()), TES3RecordIterator());
	}

}
