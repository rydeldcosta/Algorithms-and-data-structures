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

int n,m,arr[200][200],dp[200][200];

/*int solve(int i,int j)
{
	if(i==0)
		return dp[i][j] = arr[i][j];
	if(dp[i][j])
		return dp[i][j];
	int mx = INT_MIN;
	mx = max(mx,solve(i-1,j));
	if(j>0)
		mx = max(mx,solve(i-1,j-1));
	if(j<m-1)
		mx = max(mx,solve(i-1,j+1));
	//cout<<mx<<" ";
	dp[i][j] = arr[i][j] + mx;
	return dp[i][j];
}*/
int solve()
{
	int i,j,mx;
	F(i,0,m)
		dp[0][i] = arr[0][i];
	F(i,0,n)
	{
		F(j,0,m)
		{
			int mx = INT_MIN;
			mx = max(mx,dp[i-1][j]);
			if(j>0)
				mx = max(mx,dp[i-1][j-1]);
			if(j<m-1)
				mx = max(mx,dp[i-1][j+1]);
			
			dp[i][j] = mx + arr[i][j];
		}
	}
	mx = INT_MIN;
	F(i,0,m)
		mx = max(mx,dp[n-1][i]);
	return mx;
}
int main()
{
	int t;
	s(t);
	while(t--)
	{
		s(n),s(m);
		int i,j,mx,maxi;
		F(i,0,n)
		{
			F(j,0,m)
			{
				s(arr[i][j]);
			}
		}
		mx = INT_MIN;
		F(i,0,m)
		{
			if(mx<arr[n-1][i])
			{
				mx = arr[n-1][i];
				maxi = i;
			}
		}
		M(dp,0);
		cout<<solve()<<endl;
		
	}
}
