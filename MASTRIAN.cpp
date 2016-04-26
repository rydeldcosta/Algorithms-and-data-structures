#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<deque>
#define S(x) scanf("%d",&x)
#define SLL(x) scanf("%lld",&x)
#define P(x) printf("%d",x)
#define PLL(x) printf("%lld",x)
#define lli long long int 
#define MOD 1000000007
#define pb(x) push_back(x)
using namespace std;

void solve(lli n,lli m)
{
	lli sum = 0;
	lli x = min(n,m);
	for(long long i=0;i<x;i++)
	{
		sum+= ((n-i)*(m-i)*2)%MOD;
	}
	printf("%lld\n", sum);
}

int main()
{
	lli t;
	SLL(t);
	while(t--)
	{
		lli n,m;
		SLL(n);
		SLL(m);
		solve(n,m);
	}
}

