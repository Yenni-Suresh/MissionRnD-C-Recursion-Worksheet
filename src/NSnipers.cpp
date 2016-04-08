/*
There is a general and he has N Snipers in his control . He has a battefield of NxN Blocks .
He now has to place all N snipers in the battle field such that he can have control of all Blocks,
ie each block should atleast have One sniper having control on it .

A Sniper has control of all blocks in line in all 4 directions . and also all blocks in all 4 diagonals
from his position .

Example :

. C C C
C C S C
. C C C
C . C .

In the above field if Sniper S is placed at (1,2) He has control of all blocks denoted by C .
But their is a problem for the General. All his snipers dont like each other So if any sees any
other sniper in his field of view (Control Blocks) ,he will instantly kill the other sniper .So
Your task is to help the general to place all his N Snipers on NxN field such that ,No sniper can
kill other sniper,but still have control of all the Blocks .

Input : A NxN board , which is all 0's , and N (number of snipers )
Output : Return 1 if its General can place all N snipers or else return 0 .
		 Also modify the battlefield ,such that Blocks which have sniper placed are denoted by 1
		 and all other blocks as 0.

		 Note : If there are multiple correct arrangements ,Arrange in any 1 of the possible ways.
Example Input :
int battle_field[4][4]={0};
solve_nsnipers(&battle_field[0][0],4);

Example Output :
Returns 1 , and modifies battle_field as follows .
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


Read :How to access elements in 2D array when its first element address is passed : http://www.geeksforgeeks.org/pass-2d-array-parameter-c/

P.S: The Above Problem is just a modified version of a popular BackTracking problem .
*/

#include "stdafx.h"
int colloid(int x, int y, int *field, int n, int i, int j)
{
	int k, l;
	if (y == j)
		return 0;
	k = i + 1;
	l = j + 1;
	while (k != x + 1)
	{
		if (k == x && l == y)
			return 0;
		k++;
		l++;
	}
	k = i + 1;
	l = j - 1;
	while (k != x + 1 && l >= 0)
	{
		if (k == x && l == y)
			return 0;
		k++;
		l--;
	}
	return 1;
}
int check(int x, int y, int *field, int n)
{
	int i, j;
	for (j = 0, i = 0; j < n && i < x; j++)
	{
		if (*((field + i*n) + j) == 1)
		{
			if (colloid(x, y, field, n, i, j) == 0)
				return 0;
			i++;
			j = -1;
		}
	}
	return 1;
}
int solve(int *field, int n, int index)
{
	int y;
	for (y = 0; y < n && index < n; y++)
	{
		if (check(index, y, field, n) == 1)
		{
			*((field + index*n) + y) = 1;
			if (solve(field, n, index + 1) == 0)
				*((field + index*n) + y) = 0;
			else return 1;
		}

	}
	if (y < n && index == n)
		return 1;
	else return 0;
}
int solve_nsnipers(int *battlefield, int n){
	if (battlefield == NULL || n < 1)
		return 0;
	return solve(battlefield, n, 0);
}
