#include "SCPT.h"

namespace libtes3
{

	SCPT::SCPT(const TES3Record& from)
	{
		for (const auto& subrecord : from)
		{
			auto reader = subrecord.data();

			if (subrecord.type() == MakeRecordType('SCHD'))
			{
				reader.readString(m_name, 32);

				m_name = m_name.substr(0, strnlen(m_name.data(), m_name.size())); // trim to null terminator
			}
			else if (subrecord.type() == MakeRecordType('SCVR'))
			{
				while (!reader.eof())
				{
					std::string_view local;
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

	std::string_view SCPT::name() const
	{
		return m_name;
	}

	std::vector<std::string_view> SCPT::locals() const
	{
		return m_locals;
	}

	std::string_view SCPT::script() const
	{
		return m_script;
	}

}
