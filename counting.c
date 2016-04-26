#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int arr[n], b[200000] ,/*b[20000] = {0}*/ max = 0, i;
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++)
		{
			scanf("%d", &arr[i]);
			b[arr[i]]++;
			if(b[arr[i]]>=max)
				max = b[arr[i]];
		}
		printf("%d\n", n-max);
		/*for(i=1;i<20000;i++)
		{
			if(b[i]==max)
				break;
		}*/
		//printf("%d %d\n", i, max);
	}
	return 0;
}
