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
	map<int, pair<int,int> > M;
	s(t);
	while(t--)
	{
		int n;
		s(n);
		int arr[n][n];
		int i,j;
		F(i,0,n)
		{
			F(j,0,n)
			{
				s(arr[i][j]);
				M[arr[i][j]] = make_pair(i,j);
				
			}
		}
		int ans=0;
		int a=M[1].first,b=M[1].second;
		F(i,2,n*n+1)
		{
			
			int x=M[i].first,y=M[i].second;
		//	cout<<x<<" "<<y<<" ";
			ans += abs(x-a) + abs(y-b);
			a= x;
			b=y;
		}
		printf("%d\n",ans);
	}
}
