#ifndef TES3SUBRECORD_H
#define TES3SUBRECORD_H

#include <optional>
#include "TES3RecordType.h"
#include "TES3PluginReader.h"

namespace libtes3
{

	class TES3Subrecord
	{
	public:
		TES3Subrecord(TES3PluginReader& reader);

		TES3Plugin* plugin() const;
		TES3PluginReader subrecordData() const;

		TES3RecordType subrecordType() const;

	private:
		TES3PluginReader m_reader;
		TES3RecordType m_type = 0;
	};

}

#endif
