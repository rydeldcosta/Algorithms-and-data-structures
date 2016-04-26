#include<stdio.h>
int count;
void Merge(int left[], int n1,int right[],int n2, int a[])
{
	int i=0, j=0, k=0;
	while(i<n1 &&j<n2)
	{
		if(left[i]<right[j])
		{
			a[k]=left[i];
			k++;
			i++;
		}
		else
		{
			count++;
			a[k]=right[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		a[k]=left[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=right[j];
		j++;
		k++;
	}
}

void Mergesort(int a[],int n)
{
	if(n<2)
		return;
	int mid=n/2;
	//int left[mid];
	//int right[n-mid];
	int *left = (int*)malloc(mid*sizeof(int)); 
	int *right = (int*)malloc((n- mid)*sizeof(int));
	int i;
	for(i=0;i<mid;i++)
	{
		left[i]=a[i];
	}
	for(i=mid;i<n;i++)
	{
		right[i-mid]=a[i];
	}
	Mergesort(left,mid);
	Mergesort(right,n-mid);
	Merge(left,mid,right,n-mid,a);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		
	
	count = 0;
	int n;
	scanf("%d", &n);
	long long a[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	Mergesort(a,n);
//	for(i=0;i<n;i++)
	{
//		printf("%d ", a[i]);
		
	}
	//cout<<count;
	printf("%d\n", count);
}
	return 0;
}
