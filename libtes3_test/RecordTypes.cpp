#include "CppUnitTest.h"

#include "libtes3.h"

using namespace libtes3;
using namespace std::string_view_literals;

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
	TEST_METHOD(ReadTES3)
	{
		bool foundRecord = false;

		for (const auto& tes3 : g_plugin->records<TES3>())
		{
			foundRecord = true;
			Assert::AreEqual(1.2f, tes3.version());
		}

		Assert::IsTrue(foundRecord);
	}

	TEST_METHOD(ReadGMST)
	{
		bool foundRecord = false;

		for (const auto& gmst : g_plugin->records<GMST>())
		{
			if (gmst.name() == "sOK")
			{
				foundRecord = true;
				Assert::AreEqual("OK"sv, gmst.value());
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
				Assert::AreEqual("Tx_sand_01.tga"sv, ltex.texture());
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
				Assert::AreEqual("Marker_Arrow.nif"sv, stat.model());
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
				Assert::IsTrue(scpt.script().find("Begin ajiraReports") != std::string_view::npos);
			}
		}

		Assert::IsTrue(foundRecord);
	}

	TEST_METHOD(ReadACTI)
	{
		bool foundRecord = false;

		for (const auto& acti : g_plugin->records<ACTI>())
		{
			if (acti.name() == "furn_sign_inn_01")
			{
				foundRecord = true;
				Assert::AreEqual("Imperial Tavern"sv, acti.friendlyName());
			}
		}

		Assert::IsTrue(foundRecord);
	}

	TEST_METHOD(ReadCONT)
	{
		bool foundRecord = false;

		for (const auto& cont : g_plugin->records<CONT>())
		{
			if (cont.name() == "crate_01")
			{
				foundRecord = true;
				Assert::AreEqual("Crate"sv, cont.friendlyName());
			}
		}

		Assert::IsTrue(foundRecord);
	}

	TEST_METHOD(ReadDOOR)
	{
		bool foundRecord = false;

		for (const auto& door : g_plugin->records<DOOR>())
		{
			if (door.name() == "in_c_door_arched")
			{
				foundRecord = true;
				Assert::AreEqual("Sturdy Arched Door"sv, door.friendlyName());
			}
		}

		Assert::IsTrue(foundRecord);
	}

	TEST_METHOD(ReadLIGH)
	{
		bool foundRecord = false;

		for (const auto& ligh : g_plugin->records<LIGH>())
		{
			if (ligh.name() == "light_com_candle_03")
			{
				foundRecord = true;
				Assert::AreEqual("Silver Candlestick"sv, ligh.friendlyName());
			}
		}

		Assert::IsTrue(foundRecord);
	}

	TEST_METHOD(ReadCELL)
	{
		bool foundRecord = false;

		for (const auto& cell : g_plugin->records<CELL>())
		{
			if (cell.name() == "Addamasartus")
			{
				foundRecord = true;
				Assert::AreEqual(size_t(285), cell.references().size());
			}
		}

		Assert::IsTrue(foundRecord);
	}
};

}
