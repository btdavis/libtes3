#include "CELLRef.h"

namespace libtes3
{
	CELLRef::CELLRef(TES3Plugin* plugin)
		: m_plugin(plugin)
	{
	}

	TES3Plugin* CELLRef::plugin() const
	{
		return m_plugin;
	}

	void CELLRef::addSubrecord(const TES3Subrecord& subrecord)
	{
		auto reader = subrecord.subrecordData();

		if (subrecord.subrecordType() == MakeRecordType('FRMR'))
		{
			reader.read(m_refId);
		}
		else if (subrecord.subrecordType() == MakeRecordType('NAME'))
		{
			reader.readString(m_name);
		}
		else if (subrecord.subrecordType() == MakeRecordType('DELE'))
		{
			reader.read(m_deleted);
		}
		else if (subrecord.subrecordType() == MakeRecordType('UNAM'))
		{
			reader.read(m_blocked);
		}
		else if (subrecord.subrecordType() == MakeRecordType('DATA'))
		{
			reader.read(m_transform);
		}
		else if (subrecord.subrecordType() == MakeRecordType('XSCL'))
		{
			reader.read(m_scale);
		}
		else if (subrecord.subrecordType() == MakeRecordType('DNAM'))
		{
			reader.readString(m_doorCell);
		}
		else if (subrecord.subrecordType() == MakeRecordType('DODT'))
		{
			reader.read(m_doorTransform);
		}
		else if (subrecord.subrecordType() == MakeRecordType('KNAM'))
		{
			reader.readString(m_key);
		}
		else if (subrecord.subrecordType() == MakeRecordType('FLTV'))
		{
			reader.read(m_lockLevel);
		}
		else if (subrecord.subrecordType() == MakeRecordType('TNAM'))
		{
			reader.readString(m_trap);
		}
		else if (subrecord.subrecordType() == MakeRecordType('ANAM'))
		{
			reader.readString(m_owner);
		}
		else if (subrecord.subrecordType() == MakeRecordType('BNAM'))
		{
			reader.readString(m_global);
		}
		else if (subrecord.subrecordType() == MakeRecordType('INTV'))
		{
			reader.read(m_uses);
		}
		else if (subrecord.subrecordType() == MakeRecordType('XSOL'))
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
