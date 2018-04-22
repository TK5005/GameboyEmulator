#include "stdafx.h"
#include "GameboyMemory.h"


GameboyMemory::GameboyMemory()
{
	clear();
}

GameboyMemory::~GameboyMemory()
{
}

bool GameboyMemory::loadOpcodes(unsigned short startLocation, unsigned char codes[])
{
	for (unsigned short i = 0; i < sizeof(codes); ++i)
	{
		memory[startLocation + i] = codes[i];
	}
	return true;
}

bool GameboyMemory::loadOpcodes(unsigned short startLocation, const char* filename)
{
/*	printf("Loading: %s\n", filename);

	// Open file
	FILE * pFile = fopen(filename, "rb");
	if (pFile == NULL)
	{
		fputs("File error", stderr);
		return false;
	}

	// Check file size
	fseek(pFile, 0, SEEK_END);
	long lSize = ftell(pFile);
	rewind(pFile);
	printf("Filesize: %d\n", (int)lSize);

	// Allocate memory to contain the whole file
	char * buffer = (char*)malloc(sizeof(char) * lSize);
	if (buffer == NULL)
	{
		fputs("Memory error", stderr);
		return false;
	}

	// Copy the file into the buffer
	size_t result = fread(buffer, 1, lSize, pFile);
	if (result != lSize)
	{
		fputs("Reading error", stderr);
		return false;
	}

	// Copy buffer to Chip8 memory
	if ((MEMORY_SIZE - startLocation) > lSize)
	{
		for (int i = 0; i < lSize; ++i)
			memory[i + startLocation] = buffer[i];
		printf("File Loaded");
	}
	else
		printf("Error: ROM too big for memory");

	// Close file, free buffer
	fclose(pFile);
	free(buffer);
	*/
	return true;
}

unsigned char GameboyMemory::getValue(unsigned short location)
{
	if (location >= 0 && location < MEMORY_SIZE)
	{
		return memory[location];
	}
	else {
		throw GameboyMemoryException::out_of_range();
	}
}

void GameboyMemory::setValue(unsigned short location, unsigned char value)
{
	if (location >= 0 && location < MEMORY_SIZE)
	{
		memory[location] = value;
	}
	else {
		throw GameboyMemoryException::out_of_range();
	}
}

void GameboyMemory::clear()
{
	for (int i = 0; i < MEMORY_SIZE; ++i)
	{
		setValue(i, 0);
	}
}

bool GameboyMemory::isClear()
{
	for (int i = 0; i < MEMORY_SIZE; i++)
	{
		if (memory[i] != 0)
		{
			return false;
		}
	}
	return true;
}