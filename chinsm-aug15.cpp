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

int dp[1003][1003];
lli f[1003][1003];

int main()
{
	int n,k,i,j;
	s(n),s(k);
	int arr[n];
	F(i,0,n)
	{
		s(arr[i]);
	}

	F(i,0,n)
	{
		F(j,i,n)
		{
	
			if(arr[i]%arr[j]==k)
			{
				dp[i][j]=1;
				f[i][j]=(i+1)*(n-j);
			}
		}
	}
	

	cout<< n*(n+1)/2-c<<endl;
}
