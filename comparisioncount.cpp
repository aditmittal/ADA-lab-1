#include<iostream>
using namespace std;


int bscount(int a[],int n)
{
	int j,i,temp,count=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j-1])
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				count++;
			}
		}
	}
	return count;
}

int sscount(int a[],int n)
{
	int i,j,min_idx,count=0;
	for(i=0;i<n-1;i++)
	{
		min_idx = i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min_idx])
			{
				min_idx = j;
				count++;
			}
		}
	}
	return count;
}
int combine(int a[],int low,int mid,int high)
{
	int i,j,k,count=0;
	i=low;
	j=mid+1;
	k = low;
	int c[100];
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			c[k] = a[i];
			k++;i++;
			count++;
		
		}
		else
		{
			c[k] = a[j];
			k++;j++;
			count++;
		}
	}
	if(i>mid)
	{
		while(j<=high)
		{
			c[k]=a[j];
			k++;
			j++;
		}
	}
	if(j>high)
	{
		while(i<=mid)
		{
			c[k]=a[i];
			k++;i++;
		}
	}
	for(i=low;i<=high;i++)
	{
		a[i] = c[i];
	}
	return count;
}
int split(int a[],int low,int high)
{
	int count=0;
	int mid,b=0;
	if(low<high)
	{
		mid = (low + high)/2;
		split(a,low,mid);
		split(a,mid+1,high);
		b=combine(a,low,mid,high);
	}
	return b;
}
int mscount(int a[],int n)
{
	return split(a,0,n-1);
}
void cocount(int a[],int n)
{
	int bc,sc,mc;
	bc = bscount(a,n);
	sc = sscount(a,n);
	mc = mscount(a,n);
	cout<<"number of comparision in bubble sort are: "<<bc<<"\n";
	cout<<"number of comparision in selection sort are: "<<sc<<"\n";
	cout<<"number of comparision in merge sort are: "<<mc<<"\n";
}

int main()
{
	int a[100],n,i;
	cout<<"enter number of elements in array";
	cin>>n;
	cout<<"\n enter array";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cocount(a,n);
	return 0;
}