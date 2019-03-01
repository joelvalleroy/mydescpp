//DES in C++ by JV
//made for a class

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <algorithm>

std::string action;
using namespace std;

unsigned long long int pc1(unsigned long long int key);
unsigned long long int pc2(unsigned long long int key);
unsigned long long int ip(unsigned long long int block);
unsigned long long int shifter(unsigned long long int num, int numShift);
unsigned long long int concat(unsigned long long int left, unsigned long long int right);
unsigned long long int f(unsigned long long int block, unsigned long long int key);
unsigned long long int expand(unsigned long long int);
unsigned long long int sboxes(unsigned long long int num);
unsigned long long int bitCol(unsigned long long int B);
unsigned long long int bitRow(unsigned long long int B);
unsigned long long int p(unsigned long long int block);
unsigned long long int ip1(unsigned long long int block);
int intToHex(unsigned long long int num, int which);
unsigned long long int parseKeyString(string keyString); 
unsigned long long int charString(string input);
unsigned long long int hexString(string input);
unsigned long long int K1 = 0, K2 = 0, K3 = 0, K4 = 0, K5 = 0, K6 = 0, K7 = 0, K8 = 0, 
                K9 = 0, K10 = 0, K11 = 0, K12 = 0, K13 = 0, K14 = 0, K15 = 0, K16 = 0;

int close()
{
	cout << endl << "Validation or other error! Please check inputs." << endl;

	exit(1);
	return 0;
}

unsigned long long int des(unsigned long long int block, unsigned long long int key)
{
	if (K1 == 0)
	{
		unsigned long long int permutedKey;
		permutedKey = pc1(key); //K+

		unsigned long long int C0;
		C0 = permutedKey & 0xFFFFFFF0000000;
		C0 = C0 >> 28;
		unsigned long long int D0;
		D0 = permutedKey & 0x0000000FFFFFFF;

		unsigned long long int C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13, C14, C15, C16;
		unsigned long long int D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, D15, D16;

		C1 = shifter(C0, 1); //shifts left by 1;
		D1 = shifter(D0, 1);
		C2 = shifter(C1, 1);
		D2 = shifter(D1, 1);

		C3 = shifter(C2, 2);
		D3 = shifter(D2, 2);
		C4 = shifter(C3, 2);
		D4 = shifter(D3, 2);
		C5 = shifter(C4, 2);
		D5 = shifter(D4, 2);
		C6 = shifter(C5, 2);
		D6 = shifter(D5, 2);
		C7 = shifter(C6, 2);
		D7 = shifter(D6, 2);
		C8 = shifter(C7, 2);
		D8 = shifter(D7, 2);

		C9 = shifter(C8, 1);
		D9 = shifter(D8, 1);

		C10 = shifter(C9, 2);
		D10 = shifter(D9, 2);
		C11 = shifter(C10, 2);
		D11 = shifter(D10, 2);
		C12 = shifter(C11, 2);
		D12 = shifter(D11, 2);
		C13 = shifter(C12, 2);
		D13 = shifter(D12, 2);
		C14 = shifter(C13, 2);
		D14 = shifter(D13, 2);
		C15 = shifter(C14, 2);
		D15 = shifter(D14, 2);

		C16 = shifter(C15, 1);
		D16 = shifter(D15, 1);

		K1 = concat(C1, D1);
		K2 = concat(C2, D2);
		K2 = concat(C2, D2);
		K3 = concat(C3, D3);
		K4 = concat(C4, D4);
		K5 = concat(C5, D5);
		K6 = concat(C6, D6);
		K7 = concat(C7, D7);
		K8 = concat(C8, D8);
		K9 = concat(C9, D9);
		K10 = concat(C10, D10);
		K11 = concat(C11, D11);
		K12 = concat(C12, D12);
		K13 = concat(C13, D13);
		K14 = concat(C14, D14);
		K15 = concat(C15, D15);
		K16 = concat(C16, D16);

		// encrypt
		if (action == "-e")
		{
			K1 = pc2(K1);
			K2 = pc2(K2);
			K3 = pc2(K3);
			K4 = pc2(K4);
			K5 = pc2(K5);
			K6 = pc2(K6);
			K7 = pc2(K7);
			K8 = pc2(K8);
			K9 = pc2(K9);
			K10 = pc2(K10);
			K11 = pc2(K11);
			K12 = pc2(K12);
			K13 = pc2(K13);
			K14 = pc2(K14);
			K15 = pc2(K15);
			K16 = pc2(K16);
		}
		else //keys for decryption
		{
			unsigned long long int T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16;
			//reverses keys, K1 for decryption is same as k16 for encyrption

			T1 = pc2(K16);
			T2 = pc2(K15);
			T3 = pc2(K14);
			T4 = pc2(K13);
			T5 = pc2(K12);
			T6 = pc2(K11);
			T7 = pc2(K10);
			T8 = pc2(K9);
			T9 = pc2(K8);
			T10 = pc2(K7);
			T11 = pc2(K6);
			T12 = pc2(K5);
			T13 = pc2(K4);
			T14 = pc2(K3);
			T15 = pc2(K2);
			T16 = pc2(K1);

			K1 = T1;
			K2 = T2;
			K3 = T3;
			K4 = T4;
			K5 = T5;
			K6 = T6;
			K7 = T7;
			K8 = T8;
			K9 = T9;
			K10 = T10;
			K11 = T11;
			K12 = T12;
			K13 = T13;
			K14 = T14;
			K15 = T15;
			K16 = T16;
		}
		
		
	}

	unsigned long long int M = block;
	M = ip(M); //permuted IP

	unsigned long long int L0 = M & 0xFFFFFFFF00000000;
	unsigned long long int R0 = M & 0x00000000FFFFFFFF;

	L0 = L0 >> 32;

	unsigned long long int L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, L16;
	unsigned long long int R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15, R16;

	L1 = R0;
	R1 = L0 ^ f(R0, K1); 

	L2 = R1;
	R2 = L1 ^ f(R1, K2);

	L3 = R2;
	R3 = L2 ^ f(R2, K3);

	L4 = R3;
	R4 = L3 ^ f(R3, K4);

	L5 = R4;
	R5 = L4 ^ f(R4, K5);

	L6 = R5;
	R6 = L5 ^ f(R5, K6);

	L7 = R6;
	R7 = L6 ^ f(R6, K7);

	L8 = R7;
	R8 = L7 ^ f(R7, K8);

	L9 = R8;
	R9 = L8 ^ f(R8, K9);

	L10 = R9;
	R10 = L9 ^ f(R9, K10);

	L11 = R10;
	R11 = L10 ^ f(R10, K11);

	L12 = R11;
	R12 = L11 ^ f(R11, K12);

	L13 = R12;
	R13 = L12 ^ f(R12, K13);

	L14 = R13;
	R14 = L13 ^ f(R13, K14);

	L15 = R14;
	R15 = L14 ^ f(R14, K15);

	L16 = R15;
	R16 = L15 ^ f(R15, K16);

	R16 = R16 << 32;

	unsigned long long int B16 = R16 | L16;

	B16 = ip1(B16);

	return B16; // should return a 64 bit integer of encrypted/unencrypted
}

unsigned long long int ip1(unsigned long long int block)
{
	unsigned long long int ipBlock = 0;

	int iparray[64]
	{ 40, 8, 48, 16, 56, 24, 64, 32,
		39, 7, 47, 15, 55, 23, 63, 31,
		38, 6, 46, 14, 54, 22, 62, 30,
		37, 5, 45, 13, 53, 21, 61, 29,
		36, 4, 44, 12, 52, 20, 60, 28,
		35, 3, 43, 11, 51, 19, 59, 27,
		34, 2, 42, 10, 50, 18, 58, 26,
		33, 1, 41, 9, 49, 17, 57, 25,
	};

	for (int i = 0; i < (sizeof(iparray) / 4); i++) {
		unsigned long long int bitshift = 64 - iparray[i];
		unsigned long long int base = 1;

		if ((block & (base << bitshift)) >= 1)
			ipBlock = ipBlock + (base << (((sizeof(iparray) / 4) - 1) - i));
	}
	return ipBlock;
}

unsigned long long int f(unsigned long long int block, unsigned long long int key)
{
	unsigned long long int expanded;
	expanded = expand(block);
	expanded = expanded ^ key; // 48 bits

	unsigned long long int sboxed = sboxes(expanded); // performs all 8 sboxes and returns 32 bits, 48 bit input
	unsigned long long int permuted = p(sboxed); //32 bits in 32 out

	return permuted;
}

unsigned long long int p(unsigned long long int block)
{
	unsigned long long int pBlock = 0;

	int pArray[32]
	{ 16, 7, 20, 21,
		29, 12, 28, 17,
		1, 15, 23, 26,
		5, 18, 31, 10,
		2, 8, 24, 14,
		32, 27, 3, 9,
		19, 13, 30, 6,
		22, 11, 4, 25,
	};

	for (int i = 0; i < (sizeof(pArray) / 4); i++) {
		unsigned long long int bitshift = 32 - pArray[i];
		unsigned long long int base = 1;

		if ((block & (base << bitshift)) >= 1)
			pBlock = pBlock + (base << (((sizeof(pArray) / 4) - 1) - i));
	}
	return pBlock;
}

unsigned long long int sboxes(unsigned long long int num)
{
	int s1[4][16] =
	{
		{ 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7, },
		{ 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8, },
		{ 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0, },
		{ 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 }
	};
	int s2[4][16] =
	{
		{ 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10, },
		{ 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5, },
		{ 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15, },
		{ 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9, },
	};
	int s3[4][16] =
	{
		{ 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8, },
		{ 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1, },
		{ 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7, },
		{ 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12, },
	};
	int s4[4][16] =
	{
		{ 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15, },
		{ 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9, },
		{ 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4, },
		{ 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14, },
	};
	int s5[4][16] =
	{
		{ 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9, },
		{ 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6, },
		{ 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14, },
		{ 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3, },
	};
	int s6[4][16] =
	{
		{ 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11, },
		{ 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, },
		{ 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, },
		{ 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13, },
	};
	int s7[4][16] =
	{
		{ 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1, },
		{ 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6, },
		{ 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, },
		{ 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12, },

	};
	int s8[4][16] =
	{
		{ 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7, },
		{ 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, },
		{ 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8, },
		{ 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11, },
	};

	unsigned long long int B1, B2, B3, B4, B5, B6, B7, B8; // will be 6 bits
	unsigned long long int B1col, B1row, B2col, B2row, B3col, B3row, B4col, B4row, B5col, B5row, B6col, B6row, B7col, B7row, B8col, B8row;
	B1 = num >> 42;
	B2 = num >> 36;
	B2 = B2 & 0x3F;
	B3 = num >> 30;
	B3 = B3 & 0x3F;
	B4 = num >> 24;
	B4 = B4 & 0x3F;
	B5 = num >> 18;
	B5 = B5 & 0x3F;
	B6 = num >> 12;
	B6 = B6 & 0x3F;
	B7 = num >> 6;
	B7 = B7 & 0x3F;
	B8 = num >> 0;
	B8 = B8 & 0x3F;

	B1col = bitCol(B1);
	B1row = bitRow(B1);
	B2col = bitCol(B2);
	B2row = bitRow(B2);
	B3col = bitCol(B3);
	B3row = bitRow(B3);
	B4col = bitCol(B4);
	B4row = bitRow(B4);
	B5col = bitCol(B5);
	B5row = bitRow(B5);
	B6col = bitCol(B6);
	B6row = bitRow(B6);
	B7col = bitCol(B7);
	B7row = bitRow(B7);
	B8col = bitCol(B8);
	B8row = bitRow(B8);

	B1 = s1[B1row][B1col]; //(eg S1B1 )
	B2 = s2[B2row][B2col];
	B3 = s3[B3row][B3col];
	B4 = s4[B4row][B4col];
	B5 = s5[B5row][B5col];
	B6 = s6[B6row][B6col];
	B7 = s7[B7row][B7col];
	B8 = s8[B8row][B8col];

	B1 = B1 << 28;
	B2 = B2 << 24;
	B3 = B3 << 20;
	B4 = B4 << 16;
	B5 = B5 << 12;
	B6 = B6 << 8;
	B7 = B7 << 4;
	B8 = B8 << 0;

	B1 = B1 | B2 | B3 | B4 | B5 | B6 | B7 | B8;

	return B1; // return 32 bits
}

unsigned long long int bitRow(unsigned long long int B)
{
	unsigned long long int row = B;

	row = B & 0x20;
	if (row > 2)
		row = row >> 4;
	if (B & 1 == 1)
		row = row + 1;

	return row;
}

unsigned long long int bitCol(unsigned long long int B)
{
	unsigned long long int col;

	col = B >> 1;
	col = col & 0x0F;

	return col;
}

unsigned long long int expand(unsigned long long int block2)
{
	unsigned long long int expanded = 0;

	int ebit[48] = {
		32, 1, 2, 3, 4, 5,
		4, 5, 6, 7, 8, 9,
		8, 9, 10, 11, 12, 13,
		12, 13, 14, 15, 16, 17,
		16, 17, 18, 19, 20, 21,
		20, 21, 22, 23, 24, 25,
		24, 25, 26, 27, 28, 29,
		28, 29, 30, 31, 32, 1, };

	for (int i = 0; i < (sizeof(ebit) / 4); i++) {
		unsigned long long int bitshift = 32 - ebit[i];
		unsigned long long int base = 1;

		if ((block2 & (base << bitshift)) >= 1)
			expanded = expanded + (base << (((sizeof(ebit) / 4) - 1) - i));
	}
	return expanded;
}

unsigned long long int ip(unsigned long long int block)
{
	unsigned long long int ipBlock = 0;

	int iparray[64]
	{ 58, 50, 42, 34, 26, 18, 10, 2,
		60, 52, 44, 36, 28, 20, 12, 4,
		62, 54, 46, 38, 30, 22, 14, 6,
		64, 56, 48, 40, 32, 24, 16, 8,
		57, 49, 41, 33, 25, 17, 9,  1,
		59, 51, 43, 35, 27, 19, 11, 3,
		61, 53, 45, 37, 29, 21, 13, 5,
		63, 55, 47, 39, 31, 23, 15, 7,
	};

	for (int i = 0; i < (sizeof(iparray) / 4); i++) {
		unsigned long long int bitshift = 64 - iparray[i];
		unsigned long long int base = 1;

		if ((block & (base << bitshift)) >= 1)
			ipBlock = ipBlock + (base << (((sizeof(iparray) / 4) - 1) - i));
	}
	return ipBlock;
}

unsigned long long int concat(unsigned long long int left, unsigned long long int right)
{
	unsigned long long int num = 0;
	num = left << 28;
	num = num | right;

	return num;
}

unsigned long long int shifter(unsigned long long int num, int numShift)
{
	unsigned long long int numTemp = num;
	unsigned long long int first = 0;

	for (int i = 0; i < numShift; i++)
	{
		numTemp = numTemp << 1;

		if (numTemp & 0x10000000)
			numTemp = numTemp + 1;

		numTemp = numTemp & 0xFFFFFFF;

	}

	return numTemp;
}

unsigned long long int pc1(unsigned long long int key)
{
	unsigned long long int pc1Key = 0;

	int pc1array[56]
	{ 57, 49, 41, 33, 25, 17, 9,
		1, 58, 50, 42, 34, 26, 18,
		10, 2, 59, 51, 43, 35, 27,
		19, 11, 3, 60, 52, 44, 36,
		63, 55, 47, 39, 31, 23, 15,
		7, 62, 54, 46, 38, 30, 22,
		14, 6, 61, 53, 45, 37, 29,
		21, 13, 5, 28, 20, 12, 4,
	};

	for (int i = 0; i < (sizeof(pc1array) / 4); i++) {
		unsigned long long int bitshift = 64 - pc1array[i];
		unsigned long long int base = 1;

		if ((key & (base << bitshift)) >= 1)
			pc1Key = pc1Key + (base << (((sizeof(pc1array) / 4) - 1) - i));
	}
	return pc1Key;
}

unsigned long long int pc2(unsigned long long int key)
{
	unsigned long long int pc2Key = 0;

	int pc2array[48]
	{ 14, 17, 11, 24, 1, 5,
		3, 28, 15, 6, 21, 10,
		23, 19, 12, 4, 26, 8,
		16, 7, 27, 20, 13, 2,
		41, 52, 31, 37, 47, 55,
		30, 40, 51, 45, 33, 48,
		44, 49, 39, 56, 34, 53,
		46, 42, 50, 36, 29, 32,
	};

	for (int i = 0; i < (sizeof(pc2array) / 4); i++) {
		unsigned long long int bitshift = 56 - pc2array[i];
		unsigned long long int base = 1;

		if ((key & (base << bitshift)) >= 1)
			pc2Key = pc2Key + (base << (((sizeof(pc2array) / 4) - 1) - i));
	}
	return pc2Key;
}

int main(int argc, char *argv[])
{
	string standard, keyString, mode, infile, outfile;
	unsigned long int firstBlockRight;
	unsigned long long int firstBlock = 0;
	unsigned long long int key;

	// DES -e 'Pa$$w0rd' CBC input.txt output.txt
	// DES -d 'Pa$$w0rd' CBC output.txt output2.txt

	//cin >> standard >> action >> keyString >> mode >> infile >> outfile;

	standard = argv[0];
	action = argv[1];
	keyString = argv[2];
	mode = argv[3];
	infile = argv[4];
	outfile = argv[5];

	auto start = chrono::steady_clock::now();

	key = parseKeyString(keyString); //change 18/16/8 char keyString to 64bit (hex-oriented)

	if (standard.compare("DES") != 0 && standard.compare("des") != 0 && standard.compare("Des") != 0 &&
		standard.compare("DeS") != 0 && standard.compare("DEs") != 0 && standard.compare("dES") != 0 &&
		standard.compare("dEs") != 0 && standard.compare("dES") != 0 && standard.compare("deS") != 0)
	{
		cout << endl << "Problem parsing standard (s/b \"DES\") " << endl; 
		close();
	}

	transform(mode.begin(), mode.end(), mode.begin(), ::toupper);

	if (mode == "ECB")
		;
	else if (mode == "CBC")
		;
	else
	{
		cout << endl << "Problem parsing mode (s/b \"ECB\ or \"CBC\") " << endl;
		close();
	}

	if (action == "-E" || action == "-e" || action.compare("-E") == 0 || action.compare("-e") == 0)
		action = "-e";
	else if (action == "-D" || action == "-d" || action.compare("-D") == 0 || action.compare("-d") == 0)
		action = "-d";
	else
		close();

	unsigned long long int IV = 0;

	ifstream infileStream(infile, ios::binary);
	ofstream outfileStream(outfile, ios::binary); //auto creates file if it does not exist

	if (infileStream.fail())
	{
		cout << endl << "input file did not open. " << endl;
		close();
	}

	infileStream.seekg(0, infileStream.end);
	int filesize = infileStream.tellg();
	infileStream.seekg(0, infileStream.beg);

	if (mode == "CBC")
	{
		if (action == "-e")
		{
			for (int i = 0; i < 4; i++)
			{
				unsigned long long int temp = rand() % 65536 + 0;
				IV = IV | temp;
				if (i != 3)
					IV = IV << 16;
			}

			//cout << "IV PL " << hex << IV << endl;
			IV = des(IV, key);
			//cout << "EN IV " << hex << IV << endl;

			outfileStream << char(intToHex(IV, 8));
			outfileStream << char(intToHex(IV, 7));
			outfileStream << char(intToHex(IV, 6));
			outfileStream << char(intToHex(IV, 5));
			outfileStream << char(intToHex(IV, 4));
			outfileStream << char(intToHex(IV, 3));
			outfileStream << char(intToHex(IV, 2));
			outfileStream << char(intToHex(IV, 1));
		}
		else if (action == "-d")
		{
			unsigned long long int temp5 = 0;
			for (int j = 0; j < 8; j++) //chars
			{
				unsigned long long int temp6 = (infileStream.get());
				temp5 = temp5 + temp6;
				if (j != 7)
					temp5 = temp5 << 8;
			}

			IV = (des(temp5, key));
			//cout << "DE IV " << hex << IV << endl;
		}
	}

	

	if (action == "-e" || action == "-d") //everything but first block and last block
	{
		firstBlockRight = filesize;

		//cout << "filesize is " << filesize << endl;

		int pad = (8 - (filesize % 8)); // how many chars need to add to the last block

		if (action == "-e") 
		{
			firstBlock = rand() % 255 + 0;;  //left half
			firstBlock = firstBlock << 32; //left half moved left
			firstBlock = firstBlock + firstBlockRight; // 64 bit, first block

			if (mode == "CBC")
			{ 
				firstBlock = firstBlock ^ IV;
			}
			unsigned long long int result = (des(firstBlock, key));

			outfileStream << char(intToHex(result, 8));
			outfileStream << char(intToHex(result, 7));
			outfileStream << char(intToHex(result, 6));
			outfileStream << char(intToHex(result, 5));
			outfileStream << char(intToHex(result, 4));
			outfileStream << char(intToHex(result, 3));
			outfileStream << char(intToHex(result, 2));
			outfileStream << char(intToHex(result, 1));
		}
		else // -d
		{
			unsigned long long int temp2 = 0;
			unsigned long long int temp1 = 0;

			temp2 = 0;

			for (int j = 0; j < 8; j++) //chars
			{
				temp1 = (infileStream.get());
				temp2 = temp2 + temp1;
				if (j != 7)
					temp2 = temp2 << 8;
			}

			unsigned long long int resultD = (des(temp2, key));

			if (mode == "CBC")
				resultD = resultD ^ IV;

			resultD = resultD & 0xFFFFFFFF;
			filesize = resultD; //iterations for decryption to run, s/b all remaining except last block
			cout << "filesize is " << dec << filesize << endl;
		}
		unsigned long long int load = 0;
		unsigned long long int test = 0;

		for (int i = 0; i < ((filesize) / 8); i++) //main part of file
		{
			test = 0;
			load = 0;
			
			for (int j = 0; j < 8; j++) //chars
			{
				test = (infileStream.get());
				load = load + test; 
				if (j != 7)
					load = load << 8; 
			}
			
			if (action == "-e" && mode == "CBC")
				load = load ^ IV;

			unsigned long long int result = (des(load, key));

			if (action == "-d" && mode == "CBC")
				result = result ^ IV;

			if (i == ((filesize / 8) - 1))
			{
				outfileStream << char(intToHex(result, 8));
				outfileStream << char(intToHex(result, 7));
				outfileStream << char(intToHex(result, 6));
				outfileStream << char(intToHex(result, 5));
				outfileStream << char(intToHex(result, 4));
				outfileStream << char(intToHex(result, 3));
				outfileStream << char(intToHex(result, 2));
				outfileStream << char(intToHex(result, 1));

				int lastRuns = 0;
				if (action == "-d")
				{
					int lastRuns = (filesize % 8);

					for (int j = 0; j < 8; j++) //chars
					{
						test = (infileStream.get());
						load = load + test;
						if (j != 7)
							load = load << 8;
					}

					unsigned long long int result = (des(load, key));

					if (action == "-d" && mode == "CBC")
						result = result ^ IV;

					for (int k = 0; k >= lastRuns; k++)
					{
						outfileStream << char(intToHex(result, (8 - k)));
					}
				}
			}
			else
			{
				outfileStream << char(intToHex(result, 8));
				outfileStream << char(intToHex(result, 7));
				outfileStream << char(intToHex(result, 6));
				outfileStream << char(intToHex(result, 5));
				outfileStream << char(intToHex(result, 4));
				outfileStream << char(intToHex(result, 3));
				outfileStream << char(intToHex(result, 2));
				outfileStream << char(intToHex(result, 1));
			}
		}

		load = 0;

		if (action == "-e") //last block
		{
			for (int i = 0; i < (filesize % 8); i++) //add remaining chars and then pad
			{
				test = (infileStream.get());
				load = load + test;
				load = load << 8;
			}

			for (int i = 0; i < pad; i++) // pad final block with some random bytes
			{
				unsigned long long int random = rand() % 255 + 0;
				load = load + random;
				load = load << 8;
			}
			if (mode == "CBC")
				load = load ^ IV;

			unsigned long long int result = (des(load, key));

			outfileStream << char(intToHex(result, 8));
			outfileStream << char(intToHex(result, 7));
			outfileStream << char(intToHex(result, 6));
			outfileStream << char(intToHex(result, 5));
			outfileStream << char(intToHex(result, 4));
			outfileStream << char(intToHex(result, 3));
			outfileStream << char(intToHex(result, 2));
			outfileStream << char(intToHex(result, 1));
		}


	}

	auto end = chrono::steady_clock::now();
	auto difference = end - start;
	int elapsedTime = chrono::duration_cast<chrono::milliseconds>(difference).count(); 
	cout << endl << "Elapsed time of DES run was : " << (elapsedTime / 1000) << "." << (elapsedTime % 1000) << " seconds" << endl;

	return 0;
}

int intToHex(unsigned long long int num, int which) 
{
	unsigned long long int copy = 0;

	if (which == 8)
		copy = num >> (56);
	if (which == 7)
		copy = num >> (48);
	if (which == 6)
		copy = num >> (40);
	if (which == 5)
		copy = num >> (32);
	if (which == 4)
		copy = num >> (24);
	if (which == 3)
		copy = num >> (16);
	if (which == 2)
		copy = num >> (8);
	if (which == 1)
		copy = num;

	copy = copy & 0x000000FF;

	unsigned long long int copy2 = copy;

	return copy2;
}

unsigned long long int parseKeyString(string keyString) 
{
	unsigned long long int key = 0;

	if (keyString.length() == 10) // strip single quotes, covert to hex
	{
		keyString.erase(keyString.begin(), keyString.begin() + 1);
		keyString.erase(keyString.end() - 1, keyString.end());
		key = charString(keyString);
	}
	else if (keyString.length() == 12) // strip double and single quotes, convert to hex
	{
		keyString.erase(keyString.begin(), keyString.begin() + 2);
		keyString.erase(keyString.end() - 2, keyString.end());
		key = charString(keyString);
	}
	else if (keyString.length() == 16) //already hex, presumably
		key = hexString(keyString);
	else
	{
		cout << "Keystring was not entered properly" << endl;
		close();
	}

	return key;
}

unsigned long long int charString (string input) //8 lenght string in
{
	unsigned long long int key = 0;;

	for (int i = 0; i < 8; i++)
	{
		unsigned long long temp = int(input.at(i));

		key = key | temp;

		if (i != 7)
			key = key << 8;

	}
	return key; 
}

unsigned long long int hexString(string input) //16 length string in
{
	unsigned long long int key = 0;;

	for (int i = 0; i < 16; i++)
	{
		char temp = int(input.at(i));
		unsigned long long int add = 0;

		if (temp == '0')
			add = 0x0;
		else if (temp == '1')
			add = 0x1;
		else if (temp == '2')
			add = 0x2;
		else if (temp == '3')
			add = 0x3;
		else if (temp == '4')
			add = 0x4;
		else if (temp == '5')
			add = 0x5;
		else if (temp == '6')
			add = 0x6;
		else if (temp == '7')
			add = 0x7;
		else if (temp == '8')
			add = 0x8;
		else if (temp == '9')
			add = 0x9;
		else if (temp == 'A')
			add = 0xA;
		else if (temp == 'B')
			add = 0xB;
		else if (temp == 'C')
			add = 0xC;
		else if (temp == 'D')
			add = 0xD;
		else if (temp == 'E')
			add = 0xE;
		else if (temp == 'F')
			add = 0xF;

		key = key | add;
		
		if (i != 15)
			key = key << 4;
	}
	return key; 
}
