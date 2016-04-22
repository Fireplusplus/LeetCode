/*
 * Set Matrix Zeroes
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0.
 * Do it in place.
 */

#include <stdio.h>
#include <stdlib.h>

#define N 3

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) 
{
	int row_has_zero = 0;
	int col_has_zero = 0;
	int i = 0, j = 0;

	for (i = 0; i < matrixColSize; i++)				//检查第一行有没有0
	{
		if (matrix[0][i] == 0)
		{
			row_has_zero = 1;	
			break;
		}
	}
	for (i = 0; i < matrixRowSize; i++)				//检查第一列有没有0
	{
		if (matrix[i][0] == 0)
		{
			col_has_zero = 1;
			break;
		}
	}
	
	for (i = 1; i < matrixRowSize; i++)				//将为0的元素的行列做标记
	{
		for (j = 1; j < matrixColSize; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}
	for (i = 1; i < matrixRowSize; i++)				//将有标记的行列对应元素都置0
	{
		for (j = 1; j < matrixColSize; j++)
		{
			if ((matrix[i][0] == 0) || (matrix[0][j] == 0))
			{
				matrix[i][j] = 0;
			}
		
		}
	}
	if (row_has_zero == 1)						
	{
		for (i = 0; i < matrixColSize; i++)
		{
			matrix[0][i] = 0;
		}
	}
	if (col_has_zero == 1)
	{
		for (i = 0; i < matrixRowSize; i++)
		{
			matrix[i][0] = 0;
		}
	}

}

int main()
{
	int * matrix[N];
	int i = 0, j = 0;
	for (i = 0; i < N; i++)
	{
		matrix[i] = (int *)malloc(N * sizeof(int));
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			matrix[i][j] = 3;
		}
	}
	matrix[1][2] = 0;
	matrix[0][1] = 0;

	setZeroes(matrix, 3, 3);
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
