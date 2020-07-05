#include "CppUnitTest.h"

#include "libtes3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace libtes3_test
{

static std::unique_ptr<TES3Plugin> g_plugin;

TEST_CLASS(RecordTypes)
{
	TEST_CLASS_INITIALIZE(ClassInitialize)
	{
		g_plugin.reset(new TES3Plugin("Morrowind.esm"));
	}

	TEST_CLASS_CLEANUP(ClassCleanup)
	{
		g_plugin.reset(nullptr);
	}

public:
	TEST_METHOD(ReadGMST)
	{
		bool foundRecord = false;

		for (const auto& gmst : g_plugin->records<GMST>())
		{
			if (gmst.name() == "sOK")
			{
				foundRecord = true;
				Assert::AreEqual("OK", gmst.value().c_str());
			}
		}

		Assert::IsTrue(foundRecord);
	}

	TEST_METHOD(ReadGLOB)
	{
		bool foundRecord = false;

		for (const auto& glob : g_plugin->records<GLOB>())
		{
			if (glob.name() == "Year")
			{
				foundRecord = true;
				Assert::AreEqual(427.0f, glob.value());
			}
		}

		Assert::IsTrue(foundRecord);
	}

	TEST_METHOD(ReadLTEX)
	{
		bool foundRecord = false;

		for (const auto& ltex : g_plugin->records<LTEX>())
		{
			if (ltex.name() == "Sand")
			{
				foundRecord = true;
				Assert::AreEqual("Tx_sand_01.tga", ltex.filename().c_str());
			}
		}

		Assert::IsTrue(foundRecord);
	}

	TEST_METHOD(ReadLAND)
	{
		bool foundRecord = false;

		for (const auto& land : g_plugin->records<LAND>())
		{
			if (land.cellX() == 19 && land.cellY() == -7)
			{
				foundRecord = true;
				Assert::AreEqual(306.0f, land.heightOffset());
			}
		}

		Assert::IsTrue(foundRecord);
	}

	TEST_METHOD(ReadSTAT)
	{
		bool foundRecord = false;

		for (const auto& stat : g_plugin->records<STAT>())
		{
			if (stat.name() == "DoorMarker")
			{
				foundRecord = true;
				Assert::AreEqual("Marker_Arrow.nif", stat.filename().c_str());
			}
		}

		Assert::IsTrue(foundRecord);
	}

	TEST_METHOD(ReadSCPT)
	{
		bool foundRecord = false;

		for (const auto& scpt : g_plugin->records<SCPT>())
		{
			if (scpt.name() == "ajiraReports")
			{
				foundRecord = true;
				Assert::IsTrue(scpt.script().find("Begin ajiraReports") != std::string::npos);
			}
		}

		Assert::IsTrue(foundRecord);
	}
};

}
