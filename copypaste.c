#include<stdio.h>


int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int arr[n];
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d" ,&arr[i]);
		}
		int j;
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					int tmp;
					tmp = arr[j];
					arr[j]=arr[j+1];
					arr[j+1] = tmp;
				}
			}
		}
		int k,p=n;
		for(i=0;i<n-1;i++)
		{
			for(j=i;j<n;j++)
			{
				if(arr[j] == arr[i])
				{
					
					for(k=j+1;k<p;k++)
					{
						arr[k-1] = arr[k];
					}
					p--;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%d ", arr[i]);
		}
	}
	return 0;
}
