#include<stdio.h>
#include<string.h>
int main()
{
	while(1)
	{
	int n;
	scanf("%d", &n);
	if(n==0)
		break;
	int i, j;
	char s[201];
	scanf("%s", s);
	int len = strlen(s);
	int r = len/n;
	char ans[r][n];
	int k =0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<n;j++)
		{
			ans[i][j]=s[k];
			k++;
		}
		i++;
		for(j=n-1;j>=0;j--)
		{
			ans[i][j]=s[k];
			k++;
		}
	}
	for(j=0;j<n;j++)
	{
		for(i=0;i<r;i++)
		{
			printf("%c", ans[i][j]);
		}
	}
	printf("\n");
	}
	
	return 0;
}
