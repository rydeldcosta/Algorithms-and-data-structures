#include<bits/stdc++.h>

#define sc(x) scanf("%s",x)
#define s(x) scanf("%d",&x)
#define lli long long int
#define MOD 1000000000

using namespace std;


int main()
{
	int t;
	s(t);
	while(t--)
	{
		int n,m;
		s(n),s(m);
		char ar[n+1][m+1];
		int br[n+1][m+1];
		
		for(int i=0;i<n;i++)
		{
			//for(int j=0;j<m;j++)
			{
				sc(ar[i]);
				//ar[i][j] = c-'0';
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
			//	sc(ar[i]);
				br[i][j] = ar[i][j]-'0';
			}
		}
		/*	for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
			//	sc(ar[i]);
				cout<<br[i][j];
			}
			cout<<endl;
		}*/
		int shadow[n][m],dp[n][m][2];
		memset(shadow,0,sizeof(shadow));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(br[i][j]==1){
				
				if(i+1<n)
					shadow[i+1][j]++;
				if(j+1<m)
					shadow[i][j+1]++;
				if(i-1>=0)
					shadow[i-1][j]++;
				if(j-1>=0)
					shadow[i][j-1]++;
			}}
		}
		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
			//	sc(ar[i]);
				cout<<shadow[i][j];
			}
			cout<<endl;
		}*/
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=dp[0][0][1]=shadow[0][0]-br[0][0];		//
		/*for(int i=0;i<n;i++)
		{
		}	dp[0][i][1] = shadow[i][j]-br[i][j];
			dp[i][0][0] = shadow[i][j]-br[i][j];
		}*/
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(i==0&&j==0)
					continue;
				if(i-1<0)
				{
					dp[i][j][0] = shadow[i][j]-br[i][j] + dp[i][j-1][0];
					dp[i][j][1] = 10000 ;
				}
				else if(j-1<0)
				{
					dp[i][j][0] = 100000 ;
					dp[i][j][1] = shadow[i][j]-br[i][j] + dp[i-1][j][1];
				}
				else
				{
					dp[i][j][0] = shadow[i][j]-br[i][j] + min(dp[i][j-1][0], dp[i][j-1][1]-br[i-1][j]);
					dp[i][j][1] = shadow[i][j]-br[i][j] + min(dp[i-1][j][1],dp[i-1][j][0]-br[i][j-1]);
				}
				
			}
		}
		int ans = min(dp[n-1][m-1][0],dp[n-1][m-1][1]) + br[0][0] + br[n-1][m-1] ; //
		cout<<ans<<endl;
	}
}
