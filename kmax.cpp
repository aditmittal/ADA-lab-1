
#include<iostream>
using namespace std;

int main()
{
	int n,k;
	cout<<"enter size of array";
	cin>>n;
	int a[n];
	cout<<"\n enter elements";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"\n enter number of largest elements to be printed: ";
	cin>>k;
	cout<<"\n the "<<k<<"th largest elements in array are\n";
	for(int j=0;j<k;j++)
	{
		int max = j;
		for(int m = j+1;m<n;m++)
		{
			if(a[max]<a[m])
			{
				max = m;
			}
		}	int temp = a[j];
		a[j] = a[max];
		a[max] = temp;
		cout<<a[j]<<" ";
	}
	cout<<"endl";
	return 0;
}