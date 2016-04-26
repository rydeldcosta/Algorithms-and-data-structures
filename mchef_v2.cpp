#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
using namespace std;
 
long long int dp[ 100023 ][ 502 ];
long long int knapSack( int S, int N,int wei[],lli value[] ) {
	lli i, w;
	//memset(dp,0,sizeof(dp));
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
		lli n,k,m;
		sl(n),sl(k),sl(m);
		lli ar[n],sum=0,value[n];
		int wei[n],weit[n],idx[n],ix=0;
		int w1=0,v1=0;
		for(lli i=0;i<n;i++)
		{
			sl(ar[i]);
			sum+=ar[i];
			ar[i]*=-1;
			if(ar[i]>0)
			{
				value[v1++]=ar[i];
				idx[ix++] = i;
				weit[w1++] = INT_MAX;
			}
		//	wei[i]=INT_MAX;
			
		}
 
		for(int i=0;i<m;i++)
		{
			int l,r,ct;
			s(l),s(r),s(ct);
 
			for(int j=0;j<ix;j++)
			{
				if(idx[j]>=l-1 && idx[j]<r)
				{
					weit[j] = min(weit[j],ct);
				}
				
			}
		//	cout<<"a";
		}
		/*for(int i=0;i<n;i++)
		{
			if(ar[i]>0)
				weit[w1++] = wei[i];
		}*/
	//	sort(all(v),cmp);
	//	cout<<"sas";
//	for(int i=0;i<w1;i++)
//		cout<<weit[i]<<" ";
	printf("%lld\n",sum+knapSack(k,w1,weit,value));
 
		
	}
}   
