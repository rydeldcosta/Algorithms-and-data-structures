#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define li long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mod 1000000007
using namespace std;

int main()
{
	int t;
	s(t);
	for(int b=1;b<=t;b++)
	{
		lli n;
		sl(n);
		if(n==0)
		{
			printf("Case %d: 0\n");
			continue;
		}	
		lli ar[n],dp[n];
		for(int i=0;i<n;i++)
		{
			sl(ar[i]);
		}
		dp[n-1] = ar[n-1];
		
		//lli sum=0;
		int flag=0;
		if(n>1)
		{
			dp[n-2] = max(dp[n-1],ar[n-2]);
			for(int i=n-2;i>=0;i--)
			{	if(flag==0)
				{
					dp[i] = max(ar[i]+dp[i+1]-ar[i+1],dp[i+1]);
					if(dp[i]==dp[i+1])
						flag=1;
				//	cout<<ar[i]<<" ";
					//flag=1;
				}
				else
				{
					dp[i] = ar[i]+dp[i+1];
					flag=0;
				//	cout<<ar[i]<<" ";
				}
			}
		}
		else
			dp[0]=ar[0];
		lli ans = dp[0];
	
		printf("Case %d: %lld\n",b,ans);
	}
	
}
