#include <stdio.h>
#include "sum_nbo.h"

uint32_t func(uint32_t input) {
	uint32_t num1;
	uint32_t num2;
	uint32_t num3;
	uint32_t num4;

	num1 = (input & 0xff000000) >> 24;
	num2 = (input & 0x00ff0000) >> 8;
	num3 = (input & 0x0000ff00) << 8;
	num4 = (input & 0x000000ff) << 24;

	return num1+num2+num3+num4;
}

int main(int argc, char* argv[]) {
	

	if (argc < 3) {
		printf("input error\n");
		return 0;
	}

	uint32_t result = 0;
	uint32_t num;

	for (int i = 1; i < argc; i++) {
		FILE *filein = fopen(argv[i], "r");
		fread(&num, 4, 1, filein);
		
		result += func(num);

		fclose(filein);
	}
	
	printf("%u\n", result);

	return 0;


}
