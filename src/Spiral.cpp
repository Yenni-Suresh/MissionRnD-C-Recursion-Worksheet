/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void get(int *result, int rows, int columns, int **input, int index, int r, int size)
{
	int i;
	if (index == size)
		return;
	for (i = r; i < columns; i++)
	{
		result[index++] = input[r][i];
	}
	for (i = r + 1; i < rows; i++)
	{
		result[index++] = input[i][columns - 1];
	}
	for (i = columns - 2; i >= r && (rows - 1 != r); i--)
	{
		result[index++] = input[rows - 1][i];
	}
	for (i = rows - 2; i > r && (r != columns - 1); i--)
	{
		result[index++] = input[i][r];
	}
	get(result, rows - 1, columns - 1, input, index, r + 1, size);
}
int *spiral(int rows, int columns, int **input_array)
{
	if (rows<1 || columns<1 || input_array == NULL)
		return NULL;
	int *result;
	result = (int*)malloc(rows*columns*sizeof(int));
	get(result, rows, columns, input_array, 0, 0, rows*columns);
	return result;
}
