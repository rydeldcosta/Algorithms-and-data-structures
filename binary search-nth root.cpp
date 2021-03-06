#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LLD long long
#define VI vector < int >
#define PII pair < int , int >
#define MAX 1000000000
LLD A[10004];
LLD C[10004];
vector<LLD> V[1000004];
LLD INF;
int N;


void gen()
{
    for(int i=3;i<=1000000;i++)
    {
	V[i].PB(0);
	V[i].PB(1);
    }

    for(LLD i=2LL;i<=1000000LL;i++)
    {
	LLD x = i*i*i;
	int pos = 3;
	while(1)
	{
	    V[pos].PB(x);
	    if(x >= (INF/(double)i) )
		break;
	    x = x*i;
	    pos++;
	}
    }
}

// calculate a^b
LLD root(int a, LLD b)
{
    if(a==1)
	return b;
    if(a==2)
	return (LLD)sqrt(b);

    // binary search for the max v such that v^a <= b
    LLD lo = 0, hi = V[a].size()-1, mid;
    LLD ans = 1;
    while(lo<=hi)
    {
	mid = (lo+hi)/2LL;
	if(V[a][mid] > b)
	    hi = mid-1;
	else
	{
	     ans = mid;
	     lo = mid+1;
	}
    }
    return ans;
}

LLD val(LLD x)
{
     LLD res = 0;
     for(int i=1;i<=N;i++)
     {
	 LLD k = root(i,x);
	 // if ith root is 1, the rest are also 1.
	 if(k == 1)
	 {
	     res += C[i-1];
	     res %= MOD;
	     return res;
	 }
	 k = k % MOD;
	 res += (k*A[i-1])%MOD;
	 res %= MOD;
     }
     return res;
}
void solve()
{
    INF  = 1000000001;
    INF = INF*INF;
    gen();
    int t, Q;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++)
	{
	    scanf("%lld",&A[i]);
	    // Remove -ve value
	    A[i] = (A[i]+MOD)%MOD;
	}

	// Calculate suffix cumulative
	C[N-1] = A[N-1];
	for(int i=N-2;i>=0;i--)
	    C[i] = (C[i+1] + A[i])%MOD;

	for(int i=0;i<Q;i++)
	{
	    LLD x;
	    scanf("%lld",&x);
	    printf("%lld ", val(x));
	}
	printf("\n");
    }
}

int main()
{
    solve();
    return 0;
}
