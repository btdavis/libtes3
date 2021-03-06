#ifndef GMST_H
#define GMST_H

#include <string>

#include "../TES3Record.h"

namespace libtes3
{

	class GMST: public TES3Record
	{
	public:
		static constexpr TES3RecordType Type = MakeRecordType('GMST');

		GMST(const TES3Record& from);

		virtual std::string id() const override;

		std::string_view name() const;
		std::string_view value() const;

	private:
		std::string_view m_name;
		std::string_view m_value;
	};

}

#endif
