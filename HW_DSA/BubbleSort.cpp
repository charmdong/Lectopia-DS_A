#include<stdio.h>
#include<time.h>    // time()
#include<stdlib.h>  // rand(), srand()
void iteratorBubbleSort(int *ary, int n);
void recursiveBubbleSort(int *ary, int n);
void initArray(int *ary, int n), printArray(int *ary, int n);
int  main()
{
	int numberArray[10], arySize;
	arySize = sizeof(numberArray) / sizeof(numberArray[0]);
	srand((unsigned int)time(NULL));

	initArray(numberArray, arySize);
	iteratorBubbleSort(numberArray, arySize);
	printArray(numberArray, arySize);

	initArray(numberArray, arySize);
	recursiveBubbleSort(numberArray, arySize);
	printArray(numberArray, arySize);

	getchar();
	return 0;
}
void iteratorBubbleSort(int *ary, int n)
{
	int i, j, tmp, target;
	for (i = 0; i < n - 1; i++)
	{
		target = 0;
		for (j = 1; j < n - i; j++)
		{
			if (ary[target] > ary[j])
			{
				tmp = ary[target];
				ary[target] = ary[j];
				ary[j] = tmp;
				target = j;
			}
			else
				target = j;
		}
	}
	return;
}
void recursiveBubbleSort(int *ary, int n)
{
	int i, tmp, target = 0;
	if (n == 1)
		return;
	for (i = 0; i < n; i++)
	{
		if (ary[target] > ary[i])
		{
			tmp = ary[target];
			ary[target] = ary[i];
			ary[i] = tmp;
			target = i;
		}
		else // ary[target] < ary[i]
			target = i;
	}
	recursiveBubbleSort(ary, n - 1);
}
void initArray(int *ary, int n)
{
	int i;
	for (i = 0; i<n; ++i)
		ary[i] = rand() % 20 + 1;
}
void printArray(int *ary, int n)
{
	int i;
	printf("배열 내용 : ");
	for (i = 0; i<n; ++i)
		printf("%4d", ary[i]);
	printf("\n");
}
