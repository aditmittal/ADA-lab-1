#include<bits/stdc++.h>
using namespace std;
int c[100][100], n;

void Dijkstra(/*int c[][100],*/ int src){
	int dist[100],vis[100], u;
	for(int i =1; i<=n;i++)
		{
			dist[i] = c[src][i];
			vis[i] = 0;
		}
	vis[src] = 1;
	dist[src] = 0;
	int count = 1;
	while(count != n)
	{
		int min = 9999;
		for(int i =1 ; i<=n; i++)
			{
				if(dist[i] < min && !vis[i]){
					min = dist[i];
					u = i;
				}
			}
		vis[u] = 1;
		count++;
		for(int i =1; i<=n;i++)
		{
			if(min+c[u][i] < dist[i] && !vis[i])
				dist[i] = min + c[u][i];
		}
	}
	cout<<"\nShortest distances are: \n";
	for(int i = 1; i<=n;  i++)
		cout<<src-1<<"->"<<i-1<<": "<<dist[i]<<endl;
}

int main()
{
	cout<<"Enter size: ";
	cin>>n;
	cout<<"\nEnter the matrix(-1 for inifinity): \n";
	for(int i = 1; i<=n;i++)
		for(int j=1; j<=n;j++)
			{
				cin>>c[i][j];
				if(c[i][j] == -1)
					c[i][j] = 10000;
			}
	Dijkstra(1);
	return 0;
}