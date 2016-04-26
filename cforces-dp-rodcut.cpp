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

int dp[4500][4500],A,B,C;
int solve(int n, int a)
{
	if(dp[n][a])
		return dp[n][a];
	if(n<a)
		return -1;
	if(n==a)
		return 1;
	if(max( solve(n-a,A) , max(solve(n-a,B),solve(n-a,C)))==-1)
		dp[n][a]=-1;
	else
		dp[n][a] = 1+max( solve(n-a,A) , max(solve(n-a,B),solve(n-a,C)));
	return dp[n][a];
}

int main()
{
	int n,a,b,c;
	s(n),s(A),s(B),s(C);
	int x,y,z;
	x = solve(n,A);
	y=solve(n,B);
	z=solve(n,C);
	x = max(x,y);
	x = max(x,z);
	cout<<x<<endl;
}
