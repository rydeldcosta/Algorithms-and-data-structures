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

int dp[100500],flg[100500];
int k,d,dpt=0;


lli solve(int n,int flag)
{
	if(n==0 && flag==1)
	{	//cout<<dpt<<endl;
		//dp[0] = 1;
		return 1;}
	if(n==0 && flag==0)
		return 0;
	if(dp[n] && flag)
	{	//cout<<dpt<<endl;
		return dp[n];
	}
	int x = min(n,k);
	int i;
	//dp[n][1] = 0;
	for(i=1;i<=x;i++)
	{
		if(i>=d || flag==1)
		{
		//	cout<<"s";
			dp[n]+=solve(n-i,1);
		//	cout<<"s";
			flg[n]=1;
		}
		else
			dp[n] +=solve(n-i,0);
		dp[n]%=MOD;
	}
//	cout<<dp[n]<<endl;
//cout<<"s";
	return dp[n];
}

int main()
{
	int n;
	s(n),s(k),s(d);
	int flag = 1;
	cout<<solve(n,0)<<endl;
}
