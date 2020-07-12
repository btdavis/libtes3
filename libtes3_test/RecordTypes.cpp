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
		auto record = g_plugin->findRecord<TES3>("");

		Assert::IsTrue(record != std::nullopt);

		if (record != std::nullopt)
		{
			Assert::AreEqual(1.2f, record->version());
		}
	}

	TEST_METHOD(ReadGMST)
	{
		auto record = g_plugin->findRecord<GMST>("sOK");

		Assert::IsTrue(record != std::nullopt);

		if (record != std::nullopt)
		{
			Assert::AreEqual("OK"sv, record->value());
		}
	}

	TEST_METHOD(ReadGLOB)
	{
		auto record = g_plugin->findRecord<GLOB>("Year");

		Assert::IsTrue(record != std::nullopt);

		if (record != std::nullopt)
		{
			Assert::AreEqual(427.0f, record->value());
		}
	}

	TEST_METHOD(ReadLTEX)
	{
		auto record = g_plugin->findRecord<LTEX>("Sand");

		Assert::IsTrue(record != std::nullopt);

		if (record != std::nullopt)
		{
			Assert::AreEqual("Tx_sand_01.tga"sv, record->texture());
		}
	}

	TEST_METHOD(ReadLAND)
	{
		auto record = g_plugin->findRecord<LAND>("(19,-7)");

		Assert::IsTrue(record != std::nullopt);

		if (record != std::nullopt)
		{
			Assert::AreEqual(306.0f, record->heightOffset());
		}
	}

	TEST_METHOD(ReadSTAT)
	{
		auto record = g_plugin->findRecord<STAT>("DoorMarker");

		Assert::IsTrue(record != std::nullopt);

		if (record != std::nullopt)
		{
			Assert::AreEqual("Marker_Arrow.nif"sv, record->model());
		}
	}

	TEST_METHOD(ReadSCPT)
	{
		auto record = g_plugin->findRecord<SCPT>("ajiraReports");

		Assert::IsTrue(record != std::nullopt);

		if (record != std::nullopt)
		{
			Assert::IsTrue(record->script().find("Begin ajiraReports") != std::string_view::npos);
		}
	}

	TEST_METHOD(ReadACTI)
	{
		auto record = g_plugin->findRecord<ACTI>("furn_sign_inn_01");

		Assert::IsTrue(record != std::nullopt);

		if (record != std::nullopt)
		{
			Assert::AreEqual("Imperial Tavern"sv, record->friendlyName());
		}
	}

	TEST_METHOD(ReadCONT)
	{
		auto record = g_plugin->findRecord<CONT>("crate_01");

		Assert::IsTrue(record != std::nullopt);

		if (record != std::nullopt)
		{
			Assert::AreEqual("Crate"sv, record->friendlyName());
		}
	}

	TEST_METHOD(ReadDOOR)
	{
		auto record = g_plugin->findRecord<DOOR>("in_c_door_arched");

		Assert::IsTrue(record != std::nullopt);

		if (record != std::nullopt)
		{
			Assert::AreEqual("Sturdy Arched Door"sv, record->friendlyName());
		}
	}

	TEST_METHOD(ReadLIGH)
	{
		auto record = g_plugin->findRecord<LIGH>("light_com_candle_03");

		Assert::IsTrue(record != std::nullopt);

		if (record != std::nullopt)
		{
			Assert::AreEqual("Silver Candlestick"sv, record->friendlyName());
		}
	}

	TEST_METHOD(ReadCELL)
	{
		auto record = g_plugin->findRecord<CELL>("Addamasartus");

		Assert::IsTrue(record != std::nullopt);

		if (record != std::nullopt)
		{
			Assert::AreEqual(size_t(285), record->references().size());
		}
	}
};

}
