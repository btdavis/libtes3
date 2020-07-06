#ifndef TES3FILE_H
#define TES3FILE_H

#include <vector>
#include "TES3Record.h"
#include "TES3RecordRange.h"
#include "TES3TypedRecordRange.h"

namespace libtes3
{

	class TES3Plugin
	{
	public:
		TES3Plugin(const char* filename);
		MemoryReader data();

		TES3RecordRange records() const;

		template<typename T>
		TES3TypedRecordRange<T> records() const
		{
			return TES3TypedRecordRange<T>(records());
		}

	private:
		MemoryReader m_reader;
		std::vector<char> m_data;
	};

}

#endif
