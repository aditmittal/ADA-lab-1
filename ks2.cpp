#include <bits/stdc++.h>
using namespace std;

int n;
int V[100][100];
 
int Knapsack(int w[], int v[], int W)
{
	for(int i = 0; i <= n; i++)
		V[i][0] = 0;
	for(int j = 1; j <= W; j++)
		V[0][j] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= W; j++)
		{
			if(j-w[i] >= 0)
				V[i][j] = max(V[i-1][j], v[i] + V[i-1][j-w[i]]);
			else
				V[i][j] = V[i-1][j];
		}
	}
	return V[n][W];
}

int main()
{
	int v[100], w[100], x;

	cout<<"\nEnter the number of the items(N): ";
	cin>>n;

	cout<<"\nEnter the weights in the array (w): ";
	for(int i = 1; i <= n; i++)
		cin>>w[i];	
	cout<<"\nEnter the value in the array (V): ";
	for(int i = 1; i <= n; i++)
		cin>>v[i];
	cout<<"\nEnter the weight(W): ";
	cin>>x;

	int a = Knapsack(w, v, x);

	cout<<"Answer: "<<a<<endl;
	return 0;
}