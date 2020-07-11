#include "TES3Plugin.h"
#include "TES3PluginReader.h"

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

		m_reader = TES3PluginReader(this, m_data.data(), m_data.size());

		char drive[_MAX_PATH] = {};
		char dir[_MAX_PATH] = {};
		char fname[_MAX_PATH] = {};
		char ext[_MAX_PATH] = {};
		_splitpath_s(filename, drive, dir, fname, ext);

		m_filename = fname;
		m_filename += ext;
	}

	std::string TES3Plugin::filename() const
	{
		return m_filename;
	}

	TES3PluginReader TES3Plugin::data() const
	{
		return m_reader.spanAll();
	}

	TES3RecordRange TES3Plugin::records() const
	{
		return TES3RecordRange(TES3RecordIterator(data()), TES3RecordIterator());
	}

}
