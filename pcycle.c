#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int a[n+1],b[n+1];
	int i;
	for(i=1;i<n+1;i++)
	{
		scanf("%d", &a[i]);
		b[i]= a[i];
	}
	int k = 1, tmp, count = 0;
	i = 1;
	
	while(i<n+1)
	{
		if(a[i]!=-1)
		{
			//y = 0;
			count++;
			k = i;
			
			while(1)
			{
				
				if(a[k]==-1)
				{
				
				break;
				}
		
				
				tmp = a[k];
				a[k] = -1;
				k = tmp;
			}
		}
		i++;
	}
	printf("%d\n", count);
	
	i = 1, k= 1;
	while(i<n+1)
	{
		if(b[i]!=-1)
		{
			
			count++;
			k = i;
			
			printf("%d ",k);
			while(1)
			{
				
				if(b[k]==-1)
				{
				printf("\n");
				//x++;
				break;
				}
		
				printf("%d ", b[k]);
				
				tmp = b[k];
				b[k] = -1;
				k = tmp;
			}
		}
		i++;
	}

	return 0;
}
