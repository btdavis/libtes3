#ifndef LTEX_H
#define LTEX_H

#include <string>

#include "../TES3Record.h"

namespace libtes3
{

	class LTEX
	{
	public:
		static constexpr TES3RecordType Type = MakeRecordType('LTEX');

		LTEX(const TES3Record& from);

		std::string name() const;
		int32_t index() const;
		std::string texture() const;

	private:
		std::string m_name;
		int32_t m_index = 0;
		std::string m_texture;
	};

}

#endif
