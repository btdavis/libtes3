#ifndef CELL_REF_H
#define CELL_REF_H

#include "../TES3Subrecord.h"
#include "../TES3Record.h"

#include <string>

namespace libtes3
{
	class CELL;

	class CELLRef
	{
	public:
#pragma pack(push)
#pragma pack(1)
		struct Transform
		{
			float m_posX = 0.0f;
			float m_posY = 0.0f;
			float m_posZ = 0.0f;
			float m_rotX = 0.0f;
			float m_rotY = 0.0f;
			float m_rotZ = 0.0f;
		};
#pragma pack(pop)

		CELLRef(const CELL& cell);

		const CELL& cell() const;
		std::string id() const;

		void addSubrecord(const TES3Subrecord& subrecord);

		uint32_t refMasterId() const;
		uint32_t refId() const;
		std::string_view name() const;

		bool deleted() const;
		bool blocked() const;

		Transform transform() const;
		float scale() const;

		std::string_view doorCell() const;
		Transform doorTransform() const;

		std::string_view key() const;
		int32_t lockLevel() const;
		std::string_view trap() const;

		std::string_view owner() const;
		std::string_view global() const;
		int32_t uses() const;
		std::string_view soul() const;

	private:
		const CELL& m_cell;

		uint32_t m_refId = 0;
		std::string_view m_name;
		int32_t m_deleted = 0;
		int8_t m_blocked = 0;

		Transform m_transform;
		float m_scale = 1.0f;

		std::string_view m_doorCell;
		Transform m_doorTransform;

		std::string_view m_key;
		int32_t m_lockLevel = 0;
		std::string_view m_trap;

		std::string_view m_owner;
		std::string_view m_global;
		int32_t m_uses = 0;
		std::string_view m_soul;
	};

}

#endif
