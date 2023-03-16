#include <stdio.h>

extern "C" int sum(int n);
extern "C" int prime(unsigned int p);
extern "C" int fibonacci(unsigned int f);

int main(){
	
	unsigned int signature=0;
	
	__asm(
		"movl $0xB1094,%%eax\n"
		"pushl %%eax\n"
		"subl $32,%%esp\n"
		:					// No outputs
		:
		:"%eax"				// Overwritten registers 
	);
	
	printf("Sum(0) = %i == 0\n",sum(0));
	printf("Sum(1) = %i == 1\n",sum(1));
	printf("Sum(5) = %i == 15\n",sum(5));
	printf("Sum(100) = %i == 5050\n",sum(100));
	
	printf("Prime(3)? %i expected 1\n",prime(3));
	printf("Prime(15)? %i expected 0\n",prime(15));
	printf("Prime(121)? %i expected 0\n",prime(121));
	printf("Prime(131)? %i expected 1\n",prime(131));
	
	printf("F(0) = %i == 0\n",fibonacci(0));
	printf("F(1) = %i == 1\n",fibonacci(1));
	printf("F(2) = %i == 1\n",fibonacci(2));
	printf("F(3) = %i == 2\n",fibonacci(3));
	printf("F(5) = %i == 5\n",fibonacci(5));
	printf("F(10) = %i == 55\n",fibonacci(10));
	
	__asm(
		"addl $32,%%esp\n"
		"popl %%eax\n"
		"movl %%eax,%0\n"
		:"=r" (signature)	// Output list
		:					// No inputs
		:"%eax"				// Overwritten registers	
	);
	
	if(signature!=0xB1094){
		printf("Signature does not match\nYou blew up the stack! >:C\n\n");
		printf("Your fake signature: %X\n",signature);
	}else{
		printf("Stack is intact, good job!\n\n");
	}
	
	printf("Press ENTER...");
	fgetc(stdin);
	return 0;
}
