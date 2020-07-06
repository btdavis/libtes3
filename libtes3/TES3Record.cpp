#include "TES3Record.h"

namespace libtes3
{

	TES3Record::TES3Record(MemoryReader& reader)
	{
		uint32_t size;

		reader.read(m_type);
		reader.read(size);
		reader.read(m_header);
		reader.read(m_flags);

		m_reader = reader.spanNext(size);
		reader.seek(size);
	}

	MemoryReader TES3Record::data() const
	{
		return m_reader.spanAll();
	}

	TES3SubrecordIterator TES3Record::begin() const
	{
		return TES3SubrecordIterator(m_reader.spanAll());
	}

	TES3SubrecordIterator TES3Record::end() const
	{
		return TES3SubrecordIterator();
	}

	TES3RecordType TES3Record::type() const
	{
		return m_type;
	}

	uint32_t TES3Record::header() const
	{
		return m_header;
	}

	uint32_t TES3Record::flags() const
	{
		return m_flags;
	}

	std::optional<TES3Subrecord> TES3Record::firstSubrecord(TES3RecordType type) const
	{
		for (const auto& subrecord : (*this))
		{
			if (subrecord.type() == type)
			{
				return subrecord;
			}
		}

		return std::nullopt;
	}

	std::vector<TES3Subrecord> TES3Record::allSubrecords(TES3RecordType type) const
	{
		std::vector<TES3Subrecord> result;

		for (const auto& subrecord : (*this))
		{
			if (subrecord.type() == type)
			{
				result.push_back(subrecord);
			}
		}

		return result;
	}

}
