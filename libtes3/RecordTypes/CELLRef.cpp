#include "CELLRef.h"

namespace libtes3
{

	void CELLRef::addSubrecord(const TES3Subrecord& subrecord)
	{
		auto reader = subrecord.data();

		if (subrecord.type() == MakeRecordType('FRMR'))
		{
			reader.read(m_refId);
		}
		else if (subrecord.type() == MakeRecordType('NAME'))
		{
			reader.readString(m_name);
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
			reader.readString(m_doorCell);
		}
		else if (subrecord.type() == MakeRecordType('DODT'))
		{
			reader.read(m_doorTransform);
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
			reader.readString(m_trap);
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

	uint32_t CELLRef::refMasterId() const
	{
		return (m_refId & 0xFF000000) >> 24;
	}

	uint32_t CELLRef::refId() const
	{
		return m_refId & 0x00FFFFFF;
	}

	std::string_view CELLRef::name() const
	{
		return m_name;
	}

	bool CELLRef::deleted() const
	{
		return m_deleted;
	}

	bool CELLRef::blocked() const
	{
		return m_blocked;
	}

	CELLRef::Transform CELLRef::transform() const
	{
		return m_transform;
	}

	float CELLRef::scale() const
	{
		return m_scale;
	}

	std::string_view CELLRef::doorCell() const
	{
		return m_doorCell;
	}

	CELLRef::Transform CELLRef::doorTransform() const
	{
		return m_doorTransform;
	}

	std::string_view CELLRef::key() const
	{
		return m_key;
	}

	int32_t CELLRef::lockLevel() const
	{
		return m_lockLevel;
	}

	std::string_view CELLRef::trap() const
	{
		return m_trap;
	}

	std::string_view CELLRef::owner() const
	{
		return m_owner;
	}

	std::string_view CELLRef::global() const
	{
		return m_global;
	}

	int32_t CELLRef::uses() const
	{
		return m_uses;
	}

	std::string_view CELLRef::soul() const
	{
		return m_soul;
	}
}
