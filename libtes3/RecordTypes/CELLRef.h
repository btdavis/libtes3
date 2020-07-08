#ifndef CELL_REF_H
#define CELL_REF_H

#include "../TES3Subrecord.h"

#include <string>

namespace libtes3
{

	class CELLRef
	{
	public:
		void addSubrecord(const TES3Subrecord& subrecord);

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

		int32_t index() const;
		std::string_view id() const;

		std::string_view global() const;

	private:
		int32_t m_index = 0;
		std::string_view m_id;
		int32_t m_deleted = 0;
		int8_t m_blocked = 0;

		Transform m_transform;
		float m_scale = 1.0f;

		std::string_view m_exitName;
		Transform m_exitTransform;

		std::string_view m_key;
		int32_t m_lockLevel = 0;
		std::string_view m_trapName;

		std::string_view m_owner;
		std::string_view m_global;
		int32_t m_uses = 0;
		std::string_view m_soul;
	};

}

#endif
