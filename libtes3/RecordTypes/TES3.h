#ifndef TES3_H
#define TES3_H

#include <string>

#include "../TES3Record.h"

namespace libtes3
{

	class TES3
	{
	public:
		static constexpr TES3RecordType Type = MakeRecordType('TES3');

		TES3(const TES3Record& from);

		struct MasterPlugin
		{
			std::string_view name;
			int64_t size;
		};

		float version() const;
		std::string_view company() const;
		std::string_view description() const;
		uint32_t countRecords() const;
		const std::vector<MasterPlugin>& masterPlugins() const;

	private:
		float m_version = 0.0f;
		std::string_view m_company;
		std::string_view m_description;
		uint32_t m_countRecords;
		std::vector<MasterPlugin> m_masterPlugins;
	};

}

#endif
