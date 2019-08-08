#include<stdio.h>
int main()
{

int a[19],n;
int max,i;
printf("enter number of elements");
scanf("%d",&n);
printf("enter array");
for(int j=0;j<n;j++)
{
	scanf("%d",&a[j]);
}
max = a[0];
for(i=1;i<n;i++)
{
	if(a[i]>max)
	{
		max = a[i];
	}
}
printf("maximum element is %d",max);
return 0;
}
