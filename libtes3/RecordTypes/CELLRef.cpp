#include "CELLRef.h"

namespace libtes3
{

	void CELLRef::addSubrecord(const TES3Subrecord& subrecord)
	{
		auto reader = subrecord.data();

		if (subrecord.type() == MakeRecordType('FNAM'))
		{
			reader.read(m_index);
		}
		else if (subrecord.type() == MakeRecordType('NAME'))
		{
			reader.readString(m_id);
		}
		else if (subrecord.type() == MakeRecordType('DELE'))
		{
			reader.read(m_deleted);
		}
		else if (subrecord.type() == MakeRecordType('UNAM'))
		{
			reader.read(m_blocked);
		}
		else if (subrecord.type() == MakeRecordType('DATA'))
		{
			reader.read(m_transform);
		}
		else if (subrecord.type() == MakeRecordType('XSCL'))
		{
			reader.read(m_scale);
		}
		else if (subrecord.type() == MakeRecordType('DNAM'))
		{
			reader.readString(m_exitName);
		}
		else if (subrecord.type() == MakeRecordType('DODT'))
		{
			reader.read(m_exitTransform);
		}
		else if (subrecord.type() == MakeRecordType('KNAM'))
		{
			reader.readString(m_key);
		}
		else if (subrecord.type() == MakeRecordType('FLTV'))
		{
			reader.read(m_lockLevel);
		}
		else if (subrecord.type() == MakeRecordType('TNAM'))
		{
			reader.readString(m_trapName);
		}
		else if (subrecord.type() == MakeRecordType('ANAM'))
		{
			reader.readString(m_owner);
		}
		else if (subrecord.type() == MakeRecordType('BNAM'))
		{
			reader.readString(m_global);
		}
		else if (subrecord.type() == MakeRecordType('INTV'))
		{
			reader.read(m_uses);
		}
		else if (subrecord.type() == MakeRecordType('XSOL'))
		{
			reader.readString(m_soul);
		}
	}

	int32_t CELLRef::index() const
	{
		return m_index;
	}

	std::string_view CELLRef::id() const
	{
		return m_id;
	}

	std::string_view CELLRef::global() const
	{
		return m_global;
	}
}
