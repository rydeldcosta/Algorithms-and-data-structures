#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
using namespace std;
 
long long int dp[ 100003 ][ 501 ];
long long int knapSack( int S, int N,int wei[],lli value[] ) {
	int i, w;
	
	{
		for(int i=0;i<=N;i++)
		{
			for(int j=0;j<=S;j++)
			{
				if(i==0||j==0)
				{
					dp[i][j]=0;
				}
				else if(wei[i-1]<=j)
				{
					dp[i][j] = max(dp[i-1][j],dp[i-1][j-wei[i-1]]+value[i-1]);
				}
				else
					dp[i][j]=dp[i-1][j];
			}
		}
	}
	
	
 
	return dp[ N ][ S ];
}
int main()
{
	int t;
	//cout<<"sas";
	s(t);
//	struct item tmp;
	while(t--)
	{
		//cout<<"sas";
		//v.clear();
		int n,k,m;
		s(n),s(k),s(m);
		lli ar[n],sum=0,value[n];
		int wei[n],weit[n];
		int w1=0,v1=0;
		for(int i=0;i<n;i++)
		{
			sl(ar[i]);
			sum+=ar[i];
			ar[i]*=-1;
			if(ar[i]>0)
			{
				value[v1++]=ar[i];
			}
			wei[i]=INT_MAX;
			
		}
 
		for(int i=0;i<m;i++)
		{
			int l,r,ct;
			s(l),s(r),s(ct);
 
			for(int j=l-1;j<r;j++)
			{
				wei[j] = min(wei[j],ct);
			}
		//	cout<<"a";
		}
		for(int i=0;i<n;i++)
		{
			if(ar[i]>0)
				weit[w1++] = wei[i];
		}
	
	printf("%lld\n",sum+knapSack(k,w1,weit,value));
 
		
	}
}  
