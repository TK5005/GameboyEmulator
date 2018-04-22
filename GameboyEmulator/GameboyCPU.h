#pragma once
#include "GameboyMemory.h"

class GameboyCPU
{
	public:
		GameboyCPU(GameboyMemory* memory);
		~GameboyCPU();
		void cycle();
	private:
		GameboyMemory * pMemory;
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
		void executeOpcode(unsigned char opcode);
		void incrementPC(int);
		void _00();
		void _06();
};