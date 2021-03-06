#include <stdio.h>
#include <stdlib.h>


using Byte = unsigned char;
using Word = unsigned short;
using u32 = unsigned int;

struct Mem
{
	static constexpr  u32 MAX_MEM = 1024 * 64;
	Byte* Data = (Byte*)malloc(MAX_MEM);
	void Initialize() 
	{
		for (u32 i = 0; i < MAX_MEM; i++) {
			*(Data+i) = 0;
		}
		displayMem();
	}

	void displayMem(void) {
		for (u32 i = 0; i < MAX_MEM; i++) {
			printf("Mem[%X] = 0x%X\n", i, *(Data + i));
		}
		printf("\n");
	}

};


struct CPU
{
	

	Word PC;      // program counter
	Word SP;      // stack pointer

	Byte A, X, Y; // registers
	
	// status register
	Byte C : 1;
	Byte Z : 1;
	Byte I : 1;
	Byte D : 1;
	Byte B : 1;
	Byte V : 1;
	Byte N : 1;

	void Reset(Mem& memory) 
	{
		PC = 0xFFFC;
		SP = 0x0100;
		C = Z = I = D = B = V = N = 0; 
		A = X = Y = 0; 
		memory.Initialize();

	}

	void Execute(u32 cycles, Mem& memory) 
	{

	}

	void displayReg(void) {


	}
};



int main() 
{
	Mem mem;

	CPU cpu;
	cpu.Reset(mem);
	cpu.Execute(2, mem);
	return 0;
}