#include<stdio.h>
void search(int a[],int k,int n)
{
	int l=0,h=n-1,m,f=0;
	while(l<=h)
	{
		m = (l + h)/2;
		
		if(k<a[m])
		{
			h = m-1;
		}
		else if(k>a[m]) 
		{
			l = m+1;
		}
		else
		{
			f=1;
			break;
		}
	}
	if(f==1)
	{
		printf("item found");
	}
	else
	{
		printf("item not found");
	}
}
int main()
{
	int a[30],k,n;
	printf("enter no. of elements");
	scanf("%d",&n);
	printf("enter array");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter item to search");
	scanf("%d",&k);
	search(a,k,n);
	return 0;
}