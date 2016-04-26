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
//#define max(x,y) x>y?x:y
//#define min(x,y) x>y?y:x
 
#define MOD 1000000007
using namespace std;

struct girl
{
	lli pos;
	lli h;
};
bool cmp(struct girl a, struct girl b)
{
	return a.h < b.h;
}
int main()
{
	int t;
	s(t);
	while(t--)
	{
		
		int n,i;lli x;
		s(n);
		struct girl ar[100600];
		F(i,0,n)
		{
			
			sl(x);
			ar[i].h = x;
			//sl(ar[i].h);
			ar[i].pos = i+1;
		}
		sort(ar,ar+n,cmp);
		//F(i,0,n)
		{
		//	cout<<ar[i].h<<" ";
		}
		lli mx , mn;
		lli ans = INT_MIN,ans1=0;
		mx = mn = ar[n-1].pos;
		for(int i=n-2;i>=0;i--)
		{
			ans1 = max(abs(mx-ar[i].pos)*ar[i].h,abs(mn-ar[i].pos)*ar[i].h);//cout<<ans<<" "<<endl;
			ans = max(ans,ans1);
			mx = max(mx,ar[i].pos);
			mn = min(mx,ar[i].pos);
		}
		cout<<ans<<endl;
	}
}
