#ifndef GMST_H
#define GMST_H

#include "TES3Record.h"
#include "TES3Subrecord.h"

class GMST : public TES3Record
{
public:
	GMST(const TES3Record& other) : TES3Record(other) {};

	std::string name();
	std::string valueAsString();

	static constexpr TES3RecordType Type = MakeRecordType('GMST');
	static constexpr TES3RecordType SubrecordNAMEType = MakeRecordType('NAME');
	static constexpr TES3RecordType SubrecordSTRVType = MakeRecordType('STRV');
	static constexpr TES3RecordType SubrecordINTVType = MakeRecordType('INTV');
	static constexpr TES3RecordType SubrecordFLTVType = MakeRecordType('FLTV');

	TES3Subrecord::Optional NAME() const;
	TES3Subrecord::Optional STRV() const;
	TES3Subrecord::Optional INTV() const;
	TES3Subrecord::Optional FLTV() const;
};

#endif
