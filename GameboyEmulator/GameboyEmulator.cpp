// GameboyEmulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameboyCPU.h"
#include "GameboyMemory.h"

int main()
{
	GameboyMemory memory;
	GameboyCPU cpu(&memory);
	unsigned short test = 0x5432;
	unsigned short test2 = test & 0x00FF;
	memory.setValue(test2, 0x54);
    return 0;
}

