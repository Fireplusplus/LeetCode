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
	int * arr[3];
	int i = 0;
	int num = 1;

	for (i = 0; i < 3; i++)
	{
		arr[i] = (int *)malloc(3 * sizeof(int));
	}
	for (i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			arr[i][j] = num++;
	}
	rotate(arr, 3, 3);
	for (i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}

	for (i = 0; i < 3; i++)
	{
		free(arr[i]);
	}
	getchar();
	return 0;
}