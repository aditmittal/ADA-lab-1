#include<bits/stdc++.h>
using namespace std;
bool heap(int A[], int n)
{
	for(int i=0; i<=n/2;i++)
	{
		if(2*i + 1 < n && A[2*i + 1] > A[i])
			return false;
		if(2*i + 2 < n && A[2*i + 2] > A[i])
			return false;
	}
	return true;
}


int main()
{
	int A[100], size;
	cout<<"Enter size: ";
	cin>>size;
	for(int i=0;i<size;i++)
		cin>>A[i];
	cout<<heap(A, size);
	return 0;
}
