/* 
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Follow up:
 * Could you do this in-place? 
 */
#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void rotate(int **matrix, int matrixRowSize, int matrixColSize) 
{
	int i = 0, j = 0;

	//沿副对角线翻转
	for (i = 0; i < matrixRowSize - 1; i++)
	{
		for (j = 0; j < matrixRowSize - i; j++)
		{
			swap(&matrix[i][j], &matrix[matrixRowSize - j - 1][matrixRowSize - i - 1]);
		}
	}
	//沿水平中线翻转
	for (i = 0; i < matrixRowSize / 2; i++)
	{
		for (j = 0; j < matrixRowSize; j++)
		{
			swap(&matrix[i][j], &matrix[matrixRowSize -i - 1][j]);
		}
	}
}
int main()
{
	//int *p = (int *)calloc(9, sizeof(int));
	//
	//for (int i = 0; i < 9; i++)
	//	p[i] = i + 1;
	//rotate(&p, 3, 3);
	//for (int i = 0; i < 9; i++)	
	//	printf("%d ", p[i]);

	getchar();
	return 0;
}