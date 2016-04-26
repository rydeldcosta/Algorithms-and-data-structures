#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,m;
		scanf("%d %d", &n, &m);
		int arr[m], b[10000]={0};
		int i,j;
		for(i=0;i<m;i++)
		{
			scanf("%d", &arr[i]);
			b[arr[i]]++;
		}
		int chef[1000],ass[1000],k=0,l=0;
		for(i=1;i<n+1;i++)
		{
			if(b[i]==0)
			{
				chef[l++]=i;
			}
		}
	
		for(i=0;i<l-1;i++)
		{
			for(j=0;j<l-1-i;j++)
			{
				if(chef[j]>chef[j+1])
				{
					int tmp;
					tmp = chef[j];
					chef[j]=chef[j+1];
					chef[j+1]=tmp;
				}
			}
		}
		for(i=0;i<l;i=i+2)
		{
			/*if(l==0)
				printf("\n");
				break;*/
			printf("%d ", chef[i]);
		}
		printf("\n");
		for(i=1;i<l;i=i+2)
		{
			if(l==1){
				printf("\n");
				break;}
			printf("%d ", chef[i]);
		}
		printf("\n");
	}
	return 0;
}
