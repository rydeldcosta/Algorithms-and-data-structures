#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);
	int ar[a], br[b],cr[c], ans[500000]={0};
	int i;
	for(i=0;i<a;i++)
	{
		scanf("%d", &ar[i]);
		ans[ar[i]]++;
	}
	for(i=0;i<b;i++)
	{
		scanf("%d", &br[i]);
		ans[br[i]]++;
	}
	for(i=0;i<c;i++)
	{
		scanf("%d", &cr[i]);
		ans[cr[i]]++;
	}
	int count = 0;
	for(i=1;i<500000;i++)
	{
		if(ans[i]>=2)
		{
			count++;
			//printf("%d\n", ans[i]);
		}
	}
	printf("%d\n", count);
	for(i=1;i<500000;i++)
	{
		if(ans[i]>=2)
		{
			//count++;
			printf("%d\n", i);
		}
	}
	return 0;
}
