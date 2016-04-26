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

lli dp[100500];

void precompute()
{
	dp[1] = 1;dp[2] = 2;int i;
	F(i,3,100500)
	{
		dp[i] = dp[i-2]+dp[i-1];
	}
}
int main()
{
	precompute();
	int t;
	s(t);
	while(t--)
	{
		lli n;
		sl(n);
		int i = 1;
		while(n>=dp[i])
		{
			i++;
		}
		cout<<i-1<<endl;
	}
}
