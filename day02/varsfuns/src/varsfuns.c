#include <stdio.h>
#include <stdlib.h>

int num1 = 123; // init -- global & static --> data
int num2;		// uninit -- global & static --> bss

// all functions --> machine level code --> text section

void func(int num)
{
	printf("Your number is %d\n", num);
}

int main(void)
{
	int num3 = 200;
	func(num3);
	return 0;
}
