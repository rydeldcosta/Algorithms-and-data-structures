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
#define eps 0.000000007
using namespace std;

int main()
{
	int t;
	s(t);
	while(t--)
	{
		map< double, set<double> > M;
		int n, k =1;
		s(n);
		int i;
		F(i,0,n)
		{
			lli a,b,c;
			sl(a),sl(b),sl(c);
			double ab,cb;
			if(b==0)
			{
				
				cb = (double)c/a;
					
				ab = -1/eps;
			}
			else
			{
				ab=(double)a/b *(-1);
				cb = (double)c/b *(-1);
			}
			{
			
					M[ab].insert(cb);
			}
		}
		int mx=-1;
		map<double, set<double> >::const_iterator it;
		for(it=M.begin();it!=M.end();it++)
		{
		//	cout<<it->second.size()<<endl<< it->first<<endl;
			//if(it->second.size() > max)
			int x = it->second.size();
				mx = max( x,mx);
		}
		printf("%d\n", mx);
		
	}
}
