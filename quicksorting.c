#include<stdio.h>
void qs(int a[],int low,int high)
{
	int pivot;
	if(low<high)
	{
		pivot = partition(a,low,high);
		qs(a,low,pivot-1);
		qs(a,pivot+1,high);
	}
}

int partition(int a[],int low,int high)
{
	int pivot = a[low];
	int i = low+1;
	int j = high;
	while(1)
	{
		while(a[i]<=pivot && i<=high){
			i=i+1;
		}
		while(a[j]>pivot && j>=low){
			j=j-1;
		}
		if(i<j)
		{
			int temp;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else{
			a[low] = a[j];
			a[j] = pivot;
			return j;
		}

	}
	
}

int main()
{
	int a[100],n;
	int j,i;
	printf("enter number of elements in array");
	scanf("%d",&n);
	printf("enter array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	qs(a,0,n-1);
	printf("\n the sorted array is\n");
	for(j=0;j<n;j++)
	{
		printf("%d ",a[j]);
	}
}
