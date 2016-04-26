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

/*bool cmp(int a,int b)
{
	int a
}*/
int main()
{
	int t;
	s(t);
//	int hash[100002],hash2[100002];
	
	while(t--)
	{
	//	M(hash,0);
	//	M(hash2,0);
		int n,d;
		s(n),s(d);
		int ar[n];
		for(int i=0;i<n;i++)
		{
			s(ar[i]);
			//hash[ar[i]]++;
		}
		sort(ar,ar+n);

		long long int sum = 0;
		for(int i=n-1;i>0;)
		{
			if(ar[i] - ar[i-1]<d)
			{
				sum+=ar[i]+ar[i-1];
				i-=2;
			}
			else
				i-=1;
		}
		
		printf("%lld\n", sum);
		
		
	}
}
