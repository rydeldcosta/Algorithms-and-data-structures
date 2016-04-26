#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,m;
		scanf("%d %d", &n, &m);
		int arr[n];
		int i,flag = 0,j;
		if(m==0||n==0){
			printf("NO\n");
			continue;}
		for(i=0;i<n;i++)
		{
			scanf("%d", &arr[i]);
		}
		for(i=1;i<pow(2,n);i++)
		{
			int sum = 0;
			for(j=0;j<n;j++)
			{
				//int sum = 0;
				if(i&(1<<j))
				{
					sum = sum + arr[j];
				}
			}
			if(sum==m)
			{
				flag = 1;
				printf("YES\n");
				break;
			}
		}
		if(flag==0)
		{
			printf("NO\n");
		}
	}
	return 0;
}
