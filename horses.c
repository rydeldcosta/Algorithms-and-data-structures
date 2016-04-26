#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		long long a[n];
		int i,j;
		for(i=0;i<n;i++)
		{
			scanf("%lld", &a[i]);
		}
		long long int ans = 1000000000;
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(abs(a[i]-a[j])<ans)
				{
					ans = abs(a[i]-a[j]);
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
