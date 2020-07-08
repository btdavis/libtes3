#include "CONT.h"

namespace libtes3
{

	CONT::CONT(const TES3Record& from)
	{
		for (const auto& subrecord : from)
		{
			auto reader = subrecord.data();

			if (subrecord.type() == MakeRecordType('NAME'))
			{
				reader.readString(m_name);
			}
			else if (subrecord.type() == MakeRecordType('MODL'))
			{
				reader.readString(m_model);
			}
			else if (subrecord.type() == MakeRecordType('FNAM'))
			{
				reader.readString(m_friendlyName);
			}
		}
	}

	std::string_view CONT::name() const
	{
		return m_name;
	}

	std::string_view CONT::model() const
	{
		return m_model;
	}

	std::string_view CONT::friendlyName() const
	{
		return m_friendlyName;
	}

}
