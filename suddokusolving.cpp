#include<iostream>
#include<stdio.h>
#include<conio.h>

#define unassigned 0
#define n 4
#define sqn 2

int grid[n][n];
using namespace std;

bool findunassignedlocation(int grid[n][n],int &row,int &col);
bool usedinrow(int grid[n][n],int row,int num);
bool usedincol(int grid[n][n],int col,int num);
bool usedinbox(int grid[n][n],int boxstartrow, int boxstartcol, int num);

bool issafe(int grid[n][n],int row, int col, int num)
{
	return !usedinrow(grid,row,num)&&!usedincol(grid,col,num)&&!usedinbox(grid,row-row%sqn,col-col%sqn,num);
}

bool solvesudoku(int grid[n][n])
{
	int row,col;
	if(!findunassignedlocation(grid,row,col))
	{
		return true;
	}
	for(int num=1;num<n;num++)
	{
		if(issafe(grid,row,col,num))
		{
			grid[row][col] = num;
			if(solvesudoku(grid))
			{
				return true;
			}
			grid[row][col] = unassigned;
		}
	}
	return false;
}

bool findunassignedlocation(int grid[n][n],int &row,int &col)
{
	for(row=0;row<n;row++)
	{
		for(col=0;col<n;col++)
		{
			if(grid[row][col] == unassigned)
			{
				return true;
			}
		}
	}
	return false;
}

bool usedinrow(int grid[n][n],int row,int num)
{
	for(int col = 0;col<n;col++)
	{
		if(grid[row][col] == num)
		{
			return true;
		}
	}
	return false;
}

bool usedincol(int grid[n][n],int col,int num)
{
	for(int row=0;row<n;row++)
	{
		if(grid[row][col] == num)
		{
			return true;
		}
	}
	return false;
}

bool usedinbox(int grid[n][n],int boxstartrow, int boxstartcol, int num)
{
	for(int row = 0;row<sqn;row++)
	{
		for(int col = 0;col<sqn;col++)
		{
			if(grid[row+boxstartrow][col + boxstartcol] == num)
			{
				return true;
			}
		}
	}
	return false;
}



int main()
{
	int sgrid[n][n];
	cout<<"\nenter matrix\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>grid[i][j];
		}
	}
	int a,k;
	solvesudoku(grid);
	cout<<"\nthe solved sudoku is\n";
	for(k=0;k<n;k++)
	{
		for(a=0;a<n;a++)
		{
			cout<<grid[k][a]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
