#ifndef GLOB_H
#define GLOB_H

#include <string>

#include "../TES3Record.h"

namespace libtes3
{

	class GLOB: public TES3Record
	{
	public:
		static constexpr TES3RecordType Type = MakeRecordType('GLOB');

		GLOB(const TES3Record& from);

		virtual std::string id() const override;

		enum class ValueType
		{
			Unknown,
			Short,
			Long,
			Float
		};

		std::string_view name() const;
		ValueType valueType() const;
		float value() const;

	private:
		std::string_view m_name;
		ValueType m_valueType = ValueType::Unknown;
		float m_value = 0.0f;
	};

}

#endif
