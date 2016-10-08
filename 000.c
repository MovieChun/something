#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

#define RUN()
int* twoSum(int* nums, int numsSize, int target);

int P1055();
int B1005();
int RUN();

void Queen(void);

int main(){
	clock_t start, end;
	printf("\n****************************\n\n");
	start = clock();
	
	Queen();
	end = clock();
	printf("\n\n*********************\ntime=%fms\n", (double)(end - start) / CLK_TCK);
	return 0;
}
