#include<bits/stdc++.h>
using namespace std;
int M[100][100],elec[100], n;
void Prims()
{
	int ne = 0;
	int mincost = 0;
	int u,v, min;
	for(int i=1; i<=n; i++)
	{
		elec[i] = 0;
	}
	elec[1] = 1;
	while( ne != n-1)
	{
		min = 9999;
		for(int i = 1; i<=n; i++)
			for(int j = 1; j<=n;j++)
				if(elec[i] == 1)
					if(M[i][j] < min){
						min = M[i][j];
						u = i;
						v = j;
					}
		if(elec[v] != 1)
		{
//			cout<<u<<" "<<v<<" "<<min;
			elec[v] = 1;
			ne++;
			mincost = mincost + min;
		}
		M[u][v] = 9999;
		M[v][u] = 9999;
	}
	cout<<"Minimum cost is:  "<<mincost<<endl;
	return;
}

int main()
{
	cout<<"Enter size: ";
	cin>>n;
	cout<<n<<"Enter the adjacency matrix: \n";
	for(int i = 1; i<=n ; i++)
		{//	cout<<"i :"<<i<<endl;
			for(int j = 1; j<=n ;j++)
				cin>>M[i][j];
		}
	for(int i = 1; i<=n ; i++)
	{//cout<<"i :"<<i<<endl;
		for(int j = 1; j<=n ;j++)
			if(M[i][j] == -1)
				M[i][j] = 10000;
	}

	cout<<endl;
	//for(int i = 1; i<=n ; i++)
          //      {       cout<<"i :"<<i<<endl;
            //            for(int j = 1; j<=n ;j++)
              //                  cout<<M[i][j]<<" ";
		//	cout<<endl;
		//}
	Prims();
	return 0;
}
