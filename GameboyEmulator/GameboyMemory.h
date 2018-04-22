#pragma once
#include <exception>

namespace GameboyMemoryException {
	class out_of_range : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "GameboyMemoryException: Out of Range";
		}
	};
}

class GameboyMemory
{
public:
	static const unsigned int MEMORY_SIZE = 65536;
	bool loadOpcodes(unsigned short startLocation, unsigned char codes[]);
	bool loadOpcodes(unsigned short startLocation, const char* filename);
	unsigned char getValue(unsigned short location);
	void setValue(unsigned short location, unsigned char value);
	void clear();
	bool isClear();
	GameboyMemory();
	~GameboyMemory();
private:
	unsigned char memory[MEMORY_SIZE];
};

