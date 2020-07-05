#include "SCPT.h"

SCPT::SCPT(const TES3Record& from)
{
	for (const auto& subrecord : from)
	{
		auto reader = subrecord.data();

		if (subrecord.type() == MakeRecordType('SCHD'))
		{
			char name[33] = {};
			reader.read(name, 32);
			m_name = name;
		}
		else if (subrecord.type() == MakeRecordType('SCVR'))
		{
			while (!reader.eof())
			{
				std::string local;
				reader.readString(local);
				m_locals.push_back(local);
			}
		}
		else if (subrecord.type() == MakeRecordType('SCTX'))
		{
			reader.readString(m_script);
		}
	}
}

std::string SCPT::name() const
{
	return m_name;
}

std::vector<std::string> SCPT::locals() const
{
	return m_locals;
}

std::string SCPT::script() const
{
	return m_script;
}
