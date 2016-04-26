#include<stdio.h>
int delDup(int arr[] ,int n)
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,i;
		scanf("%d" , &n);
		int ar1[n], ar2[n],c[n];
		for(i=0;i<n;i++)
		{
			scanf("%d", &ar1[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d", &ar2[i]);
		}
		int j;
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(ar1[j]>ar1[j+1])
				{
					int tmp;
					tmp = ar1[j];
					ar1[j]=ar1[j+1];
					ar1[j+1]=tmp;
				}
				if(ar2[j]>ar2[j+1])
				{
					int tmp;
					tmp = ar2[j];
					ar2[j]=ar2[j+1];
					ar2[j+1]=tmp;
				}
			}
		}
		int k = n-1;
		for(i=0;i<n;i++)
		{
			if(ar1[i]>ar[j])
		}
		for(i=0;i<n;i++)
		{
			if(ar1[i]<=ar2[i])
			{
				c[i]=1;
				
			}
			else
				c[i]=0;
		}
		int sum = 0;
		for(i=0;i<n;i++){
			sum = sum+c[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}
