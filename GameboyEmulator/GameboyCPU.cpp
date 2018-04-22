#include "stdafx.h"
#include "GameboyCPU.h"
#include <stdio.h>

GameboyCPU::GameboyCPU(GameboyMemory* memory) :
	pMemory(memory)
{

}

GameboyCPU::~GameboyCPU()
{

}

void GameboyCPU::cycle()
{
	unsigned char opcode = pMemory->getValue(registers.PC);
	executeOpcode(opcode);
}

void GameboyCPU::incrementPC(int amount)
{
	registers.PC += amount;
}

void GameboyCPU::executeOpcode(unsigned char opcode)
{
	switch (opcode)
	{
	case 0x00:
		_00();
		break;
	case 0x06:
		_06();
		break;
	default:
		break;
	}
}

/*
// 0x00
// NOP
*/
void GameboyCPU::_00()
{
	incrementPC(1);
}

/*
// 0x06
// Load immediate 8-bit data into B
*/
void GameboyCPU::_06()
{
	incrementPC(1);
	unsigned char XX = pMemory->getValue(registers.PC);
	registers.B = XX;
	incrementPC(1);
}