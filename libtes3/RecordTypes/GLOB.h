#ifndef GLOB_H
#define GLOB_H

#include <string>

#include "../TES3Record.h"

class GLOB
{
public:
	static constexpr TES3RecordType Type = MakeRecordType('GLOB');

	GLOB(const TES3Record& from);

	enum class ValueType
	{
		Unknown,
		Short,
		Long,
		Float
	};

	std::string name() const;
	ValueType valueType() const;
	float value() const;

private:
	std::string m_name;
	ValueType m_valueType = ValueType::Unknown;
	float m_value = 0.0f;
};

#endif
