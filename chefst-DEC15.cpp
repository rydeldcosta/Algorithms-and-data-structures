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

int main()
{
	int t;
	s(t);
	while(t--)
	{
		lli n1,n2,m,ans;
		sl(n1),sl(n2),sl(m);
		lli sum = m*(m+1)/2;
		lli mi,mx;
		mi = min(n1,n2);
		if(sum>=mi)
		{
			ans = max(n1,n2)-mi;
		}
		else
		{
			ans = n1-sum + n2-sum;
		}
		printf("%lld\n",ans);
	}
}
