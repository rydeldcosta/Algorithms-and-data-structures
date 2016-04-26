#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char s[100000];
	scanf("%s" , s);
	//printf("%s", s);
	int i,ans = 0;
	int n = strlen(s);
	for(i=0;i<n;i++)
	{
		if(i%2==0)
		{
			if(s[i]!='+')
				ans++;
		}
		else
		{
			if(s[i]!='-')
				ans++;
		}
	}
	if(n-ans<=ans)
	{
		ans = n-ans;
	}
	printf("%d\n", ans);
	}
	
	return 0;
}
