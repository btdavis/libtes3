#ifndef GMST_H
#define GMST_H

#include <string>

#include "../TES3Record.h"

namespace libtes3
{

	class GMST
	{
	public:
		static constexpr TES3RecordType Type = MakeRecordType('GMST');

		GMST(const TES3Record& from);

		std::string name() const;
		std::string value() const;

	private:
		std::string m_name;
		std::string m_value;
	};

}

#endif
