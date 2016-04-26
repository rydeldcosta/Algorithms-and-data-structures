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



int fastpow(int a, lli b)
{
	lli i,j,x=1,y=a;
	while(b)
	{
		if(b%2==1)
		{
			x=(x*y)%10;
		}
		y = (y*y)%10;
		b /=2;
	}
	return x%10;
}

int main()
{
	int t;
	s(t);
	while(t--)
	{
		lli b;
		char ar[1002];
		cin>>ar>>b;
		int x = ar[strlen(ar)-1] - 48;
		if(x==0)
			cout<<"0\n";
		else if (x==1)
			cout<<"1\n";
		else if(x==5)
			cout<<"5\n";
		else
			cout<<fastpow(x,b)<<endl;
	}
}
