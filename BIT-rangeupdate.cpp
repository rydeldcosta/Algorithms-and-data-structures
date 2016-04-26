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

/*BIT range update, point query*/

lli BIT[100600];
int n;		//size of BIT

void update(int x, int v)
{
	int i = x+1;
	while(i<=n)
	{
		BIT[i] += v;
		i += (i&-i);
	}
}
void range_update(int l, int r, int val)
{
	update(l,val);
	update(r+1,-val);
}

long long query(int b)
{
	lli sum = 0;
	int index = b+1;
	while(index>0)
	{
		sum+=BIT[index];
		index -= (index&-index);
	}
	return sum;
}
/*void build_BIT(int ar[])
{
	int i;
	//M(BIT,0);
	F(i,0,n)
	{
		update(i,ar[i]);
	}
	F(i,1,n+2)
		cout<<BIT[i]<<" ";
}*/



int main()
{
	int t;
	s(t);
	while(t--)
	{
		int u,i;
		s(n),s(u);
		memset(BIT,0,(n+1)*sizeof(lli));
		F(i,0,u)
		{
			int l,r,v;
			s(l),s(r),s(v);
			range_update(l,r,v);
		}
		//F(i,1,n+1)
		//	cout<<BIT[i]<<" ";
		int q;
		s(q);
		while(q--)
		{
			int x;
			s(x);
			printf("%lld\n", query(x));
		}
	}
	
}
