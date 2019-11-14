#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int a[100][100],n;
#define inf 9999
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j];
		}
		cout<<"\n";
	}
}

int main()
{
	cout<<"enter n";
	cin>>n;
	cout<<"\nenter matrix";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	floyd();
}