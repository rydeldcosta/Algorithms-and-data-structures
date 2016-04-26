#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d", &n);
	int arr[n], brr[n];
	int i;
	arr[0]=0;
	brr[0]=0;
	scanf("%d %d", &arr[0], &brr[0]);
	for(i=1;i<n;i++)
	{
		scanf("%d %d", &arr[i], &brr[i]);
		arr[i]+=arr[i-1];
		brr[i]+=brr[i-1];
	}
	struct score{
		int diff;
		int player;
	};
	struct score c[n];
	for(i=0;i<n;i++)
	{
		c[i].diff=abs(arr[i]-brr[i]);
		if(arr[i]>brr[i])
		{
			c[i].player = 1;
		}
		else
			c[i].player=2;
	}
	int max = 0, max2;
	for(i=0;i<n;i++)
	{
		if(max<=c[i].diff)
		{
			max=c[i].diff;
			max2=c[i].player;
		}
	}
	printf("%d %d" , max2, max);
	return 0;
}
