void split(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid = (low + high)/2;
		split(a,low,mid);
		split(a,mid+1,high);
		combine(a,low,mid,high);
	}
}

void combine(int a[],int low,int mid,int high)
{
	int i,j,k;
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
		}
		else
		{
			c[k] = a[j];
			k++;j++;
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
}

void main()
{
	int j,i,a[100],n;
	printf("enter number of elements in array\n");
	scanf("%d",&n);
	printf("\n enter array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	split(a,0,n-1);
	printf("\n sorted array is \n");
	for(j=0;j<n;j++)
	{
		printf("%d ",a[j]);
	}
}
