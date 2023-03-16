#include <stdio.h>

extern "C" void updateColor(unsigned colors[8][3],unsigned color,unsigned channel,unsigned value);
extern "C" unsigned int sumColors(unsigned colors[8][3]);
extern "C" unsigned int updateMatrix(unsigned** matrix,unsigned row,unsigned col,unsigned newValue);
extern "C" unsigned int sumMatrix(unsigned** matrix,unsigned rows,unsigned cols);

unsigned int** matrix;
unsigned colors[8][3] = {
	{0,0,0},
	{255,0,0},
	{0,255,0},
	{0,0,255},
	{255,255,0},
	{0,255,255},
	{255,0,255},
	{255,255,255}
};

int main(){
	matrix = new unsigned int*[10];
	unsigned int signature=0,counter=0,i,j,tmp=0;
	for(i=0;i<10;i++){
		matrix[i] = new unsigned int[10];
		for(j=0;j<10;j++){
			matrix[i][j] = ++counter;
		}
	}
	
	__asm(
		"movl $0xB1094,%%eax\n"
		"pushl %%eax\n"
		"subl $64,%%esp\n"
		:					// No outputs
		:
		:"%eax"				// Overwritten registers 
	);

	printf("Total sum before color change: %i == 3060\n",sumColors(colors));

	printf("The following color matrix should show only 32 and 196 values:\n");
	for(i=0;i<8;i++){
		for(j=0;j<3;j++){
			updateColor(colors,i,j,colors[i][j]?196:32);
			printf("%i\t",colors[i][j]);
		}
		printf("\n");
	}
	
	printf("Total sum after color change: %i == 2736\n",sumColors(colors));
	
	tmp = updateMatrix(matrix,5,4,21);
	printf("Previous value: %i == 55\nUpdated value: %i == 21\n",tmp,matrix[5][4]);
	tmp = updateMatrix(matrix,6,7,15);
	printf("Previous value: %i == 68\nUpdated value: %i == 15\n",tmp,matrix[6][7]);
	tmp = updateMatrix(matrix,2,8,59);
	printf("Previous value: %i == 29\nUpdated value: %i == 59\n",tmp,matrix[2][8]);
	tmp = updateMatrix(matrix,3,1,82);
	printf("Previous value: %i == 32\nUpdated value: %i == 82\n",tmp,matrix[3][1]);
	
	printf("Total sum of submatrix: %i == 494\n",sumMatrix(matrix,4,6));
	printf("Total sum of submatrix: %i == 625\n",sumMatrix(matrix,5,5));
	printf("Total sum of submatrix: %i == 5043\n",sumMatrix(matrix,10,10));
	
	__asm(
		"addl $64,%%esp\n"
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
