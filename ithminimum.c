#include<stdio.h>

void kthmin(int a[100],int k,int n)
{
	for(int i=0;i<k;i++)
	{
		int min = i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min = j;
				int temp;
				temp = a[j];
				a[j] = a[min];
				a[min] = temp;
			}
		}
		
	}
	printf("%d is the %dth minimum element",a[k+1],k);
}
int main()
{
	int a[100],n,k;
	printf("enter no of elemnts in array");
	scanf("%d",&n);
	printf("enter k value");
	scanf("%d",&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	kthmin(a,k,n);
}