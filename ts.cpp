#include <bits/stdc++.h>
using namespace std;

int n;
int a[100][100], indegree[100];

void topoSorting(int n)
{
	cout<<"\nTopologically Sorted: ";
	for(int i = 1; i <= n; i++)
	{
		indegree[i] = 0;
		for(int j = 1; j <= n; j++)
			{
				indegree[i] += a[j][i];
			}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(indegree[j] == 0)
			{
				cout<<j<<" ";
				indegree[j] = -1;
				for(int k = 1; k <= n; k++)
					if(a[j][k] == 1)
						indegree[k]--;
			}
		}
	}
}

int main()
{

	cout<<"\nEnter the number of nodes: ";
	cin>>n;

	cout<<"\nEnter the adjacency matrix: ";
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin>>a[i][j];

	topoSorting(n);

	cout<<endl;

	return 0;
}