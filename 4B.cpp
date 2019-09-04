#include<iostream>
#include<stdio.h>
#define ROW 3
#define COL 5

using namespace std;

int issafe(int M[ROW][COL],int row,int col,bool visited[ROW][COL])
{
	bool a;
	a = (row>=0) && (row<ROW) && (col>=0) && (col<COL) && (M[row][col] && !visited[row][col]);
	return a;
}

void dfs(int M[ROW][COL],int row,int col,bool visited[ROW][COL])
{
	static int rowNbr[] = {-1,-1,-1,0,0,1,1,1};
	static int colNbr[] = {-1,0,1,-1,1,-1,0,1};
	
	visited[row][col] = true;
	
	for(int k=0;k<8;++k)
	{
		if(issafe(M,row+rowNbr[k],col+colNbr[k],visited))
		{
			dfs(M,row+rowNbr[k],col+colNbr[k],visited);
		}
	}
}

void memset(bool v[ROW][COL],int a)
{
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			v[i][j] = a;
		}
	}
}

int countislands(int M[ROW][COL])
{
	bool visited[ROW][COL];
	memset(visited,0);
	int count = 0;
	for(int i=0;i<ROW;++i)
	{
		for(int j=0;j<COL;++j)
		{
			if(M[i][j] && !visited[i][j])
			{
				dfs(M,i,j,visited);
				++count;
			}
		}
	}
	return count;
}

int main()
{
	int co,r,c,m[ROW][COL];
	cout<<"enter matrix";
	for(r=0;r<ROW;r++)
	{
		for(c=0;c<COL;c++)
		{
			cin>>m[r][c];
		}
	}
	co = countislands(m);
	cout<<"number of elements in island is: "<<co;
}
