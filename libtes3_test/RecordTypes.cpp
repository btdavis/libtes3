#include "CppUnitTest.h"

#include "libtes3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace libtes3_test
{

TEST_CLASS(RecordTypes)
{
public:
	TEST_METHOD(ReadGMST)
	{
		TES3Plugin plugin("Morrowind.esm");

		for (const auto& gmst : plugin.records<GMST>())
		{
			if (gmst.name() == "sOK")
			{
				Assert::AreEqual("OK", gmst.value().c_str());
			}
		}
	}

	TEST_METHOD(ReadGLOB)
	{
		TES3Plugin plugin("Morrowind.esm");

		for (const auto& glob : plugin.records<GLOB>())
		{
			if (glob.name() == "Year")
			{
				Assert::AreEqual(427.0f, glob.value());
			}
		}
	}

	TEST_METHOD(ReadLTEX)
	{
		TES3Plugin plugin("Morrowind.esm");

		for (const auto& ltex : plugin.records<LTEX>())
		{
			if (ltex.name() == "Sand")
			{
				Assert::AreEqual("Tx_sand_01.tga", ltex.filename().c_str());
			}
		}
	}

	TEST_METHOD(ReadLAND)
	{
		TES3Plugin plugin("Morrowind.esm");

		for (const auto& land : plugin.records<LAND>())
		{
			if (land.cellX() == 19 && land.cellY() == -7)
			{
				Assert::AreEqual(306.0f, land.heightOffset());
			}
		}
	}
};

}
