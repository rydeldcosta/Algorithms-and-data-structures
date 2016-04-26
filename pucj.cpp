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
struct name
{
	int key,value;
};
bool cmp(struct name a, struct name b)
{
	if(a.value==b.value)
		return a.key<b.key;
	return a.value>b.value;
}
int hash[150];
int main()
{
	int t;
	s(t);
	int i,x;
	while(t--)
	{
		struct name ar[100500];
		int z=0;
		memset(hash,0,sizeof hash);
		
		int a;
		s(a);
		F(i,0,a)
		{
			int x;
			s(x);
			hash[x]++;
		}
		ar[0].key = 0;
		F(i,0,105)
		{
			if(hash[i]>0 && hash[i]%i==0)
			{
				ar[z].key = i;
				ar[z++].value = hash[i];
			}
		}
		sort(ar,ar+z,cmp);
		if(ar[0].key==0)
			printf("-1\n");
		else
		printf("%d\n",ar[0].key);
		//cout<<ar[0]<<endl;
	}
}
