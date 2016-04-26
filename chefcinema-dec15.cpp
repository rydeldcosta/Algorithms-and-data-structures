
//binary search


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

lli n,m,z,l,r,i,j;

int f(lli bs)
{
	if((l+r+z+bs<= m*n) && 	(bs <= n*ceil(m/2.0))&&	(l + r + bs + bs-n <= m*n))
		return 1;
	else
		return 0;
}

int main()
{
	int t;
	s(t);
	while(t--)
	{
		
		lli b;
		sl(n),sl(m),sl(z),sl(l),sl(r),sl(b);
		
		lli x,y;
		x= 0;
		y = b+1;
		if(l+r+z>=n*m)
		{
			cout<<n*m<<endl;
			continue;
		}
		lli mid;
		while(x<y)
		{
			 mid = x + (y-x)/2;
			if(f(mid)==1)
				x=mid+1;
			else
				y=mid;
		}
		lli bfinal = x-1;
		cout<<min((l+r+z+bfinal),n*m)<<endl;
		
	}
}
