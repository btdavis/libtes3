#include "pch.h"
#include "CppUnitTest.h"

#include <fstream>
#include <sstream>
#include <string>
#include "TES3Plugin.h"
#include "TES3Record.h"
#include "GMST.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace libtes3test
{
	TEST_CLASS(libtes3test)
	{
	public:
		
		TEST_METHOD(ReadMorrowindEsm)
		{
			TES3Plugin plugin("Morrowind.esm");

			for (const auto& record : plugin)
			{
				if (record->type() == GMST::Type)
				{
					GMST gmst = *record;
					if (gmst.name() == "sOK")
					{
						Assert::AreEqual(std::string("OK"), gmst.valueAsString());
					}
				}
			}
		}
	};
}
