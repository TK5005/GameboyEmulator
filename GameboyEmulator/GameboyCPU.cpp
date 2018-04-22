#include "stdafx.h"
#include "GameboyCPU.h"
#include <stdio.h>

GameboyCPU::GameboyCPU(GameboyMemory* memory) :
	pMemory(memory)
{
	initialize();
}

GameboyCPU::~GameboyCPU()
{

}

void GameboyCPU::initialize()
{
	reset();
}

void GameboyCPU::reset()
{
	clearRegisters();
	clearStack();
	pMemory->clear();
}

void GameboyCPU::clearRegisters()
{
	registers.A = 0x00;
	registers.B = 0x00;
	registers.C = 0x00;
	registers.D = 0x00;
	registers.E = 0x00;
	registers.F = 0x00;
	registers.H = 0x00;
	registers.L = 0x00;
	registers.SP = 0x00;
	registers.PC = 0x100;
}

void GameboyCPU::clearStack()
{
	while (!stack.empty())
	{
		stack.pop();
	}
}

void GameboyCPU::cycle()
{
	unsigned char opcode = pMemory->getValue(registers.PC);
	if (pendingMoreBytes)
	{
		(this->*opcodeFunction)(opcode);
	}
	else {
		executeOpcode(opcode);
	}
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
		_06(opcode);
		break;
	default:
		break;
	}
}

unsigned char GameboyCPU::getRegisterB()
{
	return registers.B;
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
void GameboyCPU::_06(unsigned char opcode)
{
	if (pendingMoreBytes)
	{
		pendingMoreBytes = false;
		opcodeFunction = NULL;
		unsigned char XX = pMemory->getValue(registers.PC);
		registers.B = XX;
	}
	else {
		pendingMoreBytes = true;
		opcodeFunction = &GameboyCPU::_06;
	}
	incrementPC(1);
}