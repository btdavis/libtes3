#ifndef TES3SUBRECORDITERATOR_H
#define TES3SUBRECORDITERATOR_H

#include "TES3Subrecord.h"
#include <optional>

namespace libtes3
{

	class TES3SubrecordIterator
	{
	public:
		TES3SubrecordIterator();
		TES3SubrecordIterator(const MemoryReader& reader);

		bool isValid() const;

		bool operator==(const TES3SubrecordIterator& other) const;
		bool operator!=(const TES3SubrecordIterator& other) const;

		TES3SubrecordIterator& operator++();

		TES3Subrecord& operator*();
		const TES3Subrecord& operator*() const;
		TES3Subrecord* operator->();
		const TES3Subrecord* operator->() const;

	private:
		MemoryReader m_reader;
		std::optional<TES3Subrecord> m_currentSubrecord = std::nullopt;
	};

}

#endif
