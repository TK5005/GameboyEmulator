#pragma once
#include "GameboyMemory.h"
#include <stack>

class GameboyCPU
{
	public:
		GameboyCPU(GameboyMemory* memory);
		~GameboyCPU();
		void cycle();
		unsigned char getRegisterB();
		typedef void (GameboyCPU::*ScriptFunction)(unsigned char);
		ScriptFunction opcodeFunction;
	private:
		GameboyMemory * pMemory;
		std::stack<unsigned short> stack;	// Stack
		bool pendingMoreBytes = false;
		struct
		{
			unsigned char A;
			unsigned char B;
			unsigned char C;
			unsigned char D;
			unsigned char E;
			unsigned char F;
			unsigned char H;
			unsigned char L;
			unsigned short SP;
			unsigned short PC;
		} registers;
		void initialize();
		void reset();
		void clearRegisters();
		void clearStack();
		void executeOpcode(unsigned char opcode);
		void incrementPC(int);
		void _00();
		void _06(unsigned char);
};