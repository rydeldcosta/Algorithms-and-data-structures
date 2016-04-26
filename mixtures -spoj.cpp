#include<bits/stdc++.h>
#define ull unsigned long long
#define lli long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define fr first
#define se second
#define gc getchar_unlocked
 
#define MOD 1000000007
using namespace std;

lli csum(int a,int b,int arr[]){
	lli i,sum=0;
	F(i,a,b+1){
			sum=(sum+arr[i]);
			sum%=100;
		}
	return sum;
}
lli compute(int ar[],int n)
{
	lli dp[102][102];
	memset(dp,0,sizeof dp);
	/*for(int i=0;i<n;i++)
	{
		dp[i][i] = 0;
		if(i!=n-1)
			dp[i][i+1] = (ar[i]*ar[i+1])%100;
	}
/*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
	lli minm=0;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
			minm = INT_MAX;
			for(int k=i;k<j;k++)
			{
				lli tmp = dp[i][k] + dp[k+1][j] + csum(i,k,ar)*csum(k+1,j,ar);
				if(tmp < minm)
				{
					minm = tmp;
					//cout<<a<<endl;
				//	a = (dp[i][k]);
				//	b = (dp[k+1][j]);
				}
			}
			dp[i][j] = minm;
			//sum+=(a*b);
		}
/*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
	return dp[0][n-1];
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,ar[n];
		F(i,0,n)
		{
			s(ar[i]);
		}
		cout<<compute(ar,n)<<endl;
	}
}
