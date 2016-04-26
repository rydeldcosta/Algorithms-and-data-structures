#include<bits/stdc++.h>

using namespace std;
char s[5100],dp[5100][5100];
int x;													//longest parlindromic seq
int lps()
{
	memset(dp,0,sizeof(dp));
	int i,j,k;
	for(i=0;i<x;i++)
	{
		dp[i][i]=1;
		if(s[i]==s[i+1])
		{
			dp[i][i+1]=2;
		}
		else
			dp[i][i+1]=1;
	}
	for(k=2;k<x;k++)
	{
		j=k;
		for(i=0;j<x;i++)	//
		{
			if(s[i]==s[j])
			{
				dp[i][j] = 2+dp[i+1][j-1];
			}
			else
			{
				//if(dp[i+1][j]==dp[i][j-1] &&dp[i+1][j]>1)
				//	dp[i][j] = 1 + dp[i+1][j];
				//else
					dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
			}
			j++;
		}
	}
	return dp[0][x-1];
}
					
int main()
{
	long t;
	cin>>t;
	while(t--)
	{
		scanf("%s",s);
		x = strlen(s);
		if(x==1)
		{
			cout<<"1\n";
			continue;
		}
	//	if(x>2 && x%2==0)
	//		s[x] = '&';
		cout<<x-lps()<<endl;
		
		
	}
}
