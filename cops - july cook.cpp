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
		int hash[101];
		M(hash,0);
		int m,x,y;
		s(m),s(x),s(y);
		int i,ar[m];
		for(int i=0;i<m;i++)
		{
			s(ar[i]);
			int f,j,k;
			f = x*y;
			j = ar[i]-f;
			k = ar[i]+f;
			if(j<=0)
				j=1;
			if(k>100)
				k=100;
			for(int b=j;b<=k;b++)
				hash[b]++;
				
		}
		int sum=0;
		for(int i=1;i<=100;i++)
		{
			if(hash[i]==0)
				sum++;
		}
		printf("%d\n", sum);
	}
}
