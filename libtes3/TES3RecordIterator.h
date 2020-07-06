#ifndef TES3RECORDITERATOR_H
#define TES3RECORDITERATOR_H

#include "TES3Record.h"
#include <optional>

namespace libtes3
{

	class TES3RecordIterator
	{
	public:
		TES3RecordIterator();
		TES3RecordIterator(const MemoryReader& reader);

		bool isValid() const;

		bool operator==(const TES3RecordIterator& other) const;
		bool operator!=(const TES3RecordIterator& other) const;

		TES3RecordIterator& operator++();

		TES3Record& operator*();
		const TES3Record& operator*() const;
		TES3Record* operator->();
		const TES3Record* operator->() const;

	private:
		MemoryReader m_reader;
		std::optional<TES3Record> m_currentRecord;
	};

}

#endif
