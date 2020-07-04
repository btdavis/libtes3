#include "pch.h"
#include "GMST.h"

std::string GMST::name()
{
	auto name = NAME();
	if (name)
	{
		std::string value;
		name->data().readString(value);
		return value;
	}

	return "";
}

std::string GMST::valueAsString()
{
	auto strv = STRV();
	if (strv)
	{
		std::string value;
		strv->data().readString(value);
		return value;
	}

	auto intv = INTV();
	if (intv)
	{
		int32_t value;
		strv->data().read(value);
		return std::to_string(value);
	}

	auto fltv = FLTV();
	{
		if (fltv)
		{
			float value;
			fltv->data().read(value);
			return std::to_string(value);
		}
	}

	return "";
}

TES3Subrecord::Optional GMST::NAME() const
{
	return firstSubrecord(SubrecordNAMEType);
}

TES3Subrecord::Optional GMST::STRV() const
{
	return firstSubrecord(SubrecordSTRVType);
}

TES3Subrecord::Optional GMST::INTV() const
{
	return firstSubrecord(SubrecordINTVType);
}

TES3Subrecord::Optional GMST::FLTV() const
{
	return firstSubrecord(SubrecordFLTVType);
}
