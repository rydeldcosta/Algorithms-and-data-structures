#include<bits/stdc++.h>

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define MOD 1000000000

using namespace std;

char s1[2500],s2[2500];
int dp[2500][2500];

int levenshtein(int n,int m)
{
	int i,j;
	for(i=1;i<=n;i++)
		dp[i][0]=i;
	for(i=0;i<=m;i++)
		dp[0][i]=i;
//	if(s1[0]!=s2[0])
//		dp[0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
			{
				//insert
				dp[i][j]=dp[i-1][j]+1;
				if(dp[i][j]>dp[i][j-1]+1)
					dp[i][j]=dp[i][j-1]+1;//delete
				if(dp[i][j]>dp[i-1][j-1]+1)
					dp[i][j] = dp[i-1][j-1]+1;
			}
		}
	}
	return dp[n][m];
}

int main()
{
	int t;
	s(t);
	while(t--)
	{
		int n,m;
		
		scanf("%s %s", s1,s2);
		n = strlen(s1);
		m = strlen(s2);
		int ans = 0;
		/*ans+= abs(m-n);
		for(int i = 0;i<min(n,m);i++)
		{
			if(s1[i]!=s2[i])
				ans++;
		}*/
		
		cout<<levenshtein(n,m)<<endl;
	}
}
