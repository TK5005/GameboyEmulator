#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameboyEmulator/GameboyMemory.h"
#include "../GameboyEmulator/GameboyCPU.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameboyEmulatorTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		GameboyMemory memory;

		TEST_METHOD(_06Test)
		{
			GameboyCPU cpu(&memory);
			memory.setValue(0x100, 0x06);
			memory.setValue(0x101, 0x54);
			cpu.cycle();
			cpu.cycle();
			Assert::AreEqual((unsigned char)0x54, (unsigned char)cpu.getRegisterB(), L"Incorrect value in Register B", LINE_INFO());
		}
	};
}