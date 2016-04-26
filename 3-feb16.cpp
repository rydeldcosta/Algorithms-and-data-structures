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
		int n;
		s(n);
		if(n<7){
		
			cout<<"-1\n";
			continue;
		}
		else
		{
			int div = (n-4)/3;
			vector<int> v[n+5];
			int i,j,l,r,t,d;
			t = 1,r=2,d=3,l=4;
			v[t].pb(l),v[t].pb(r),v[d].pb(l),v[d].pb(r);
			v[3].pb(5);
			int rem = n-5;
			int kg = 6;
			while(rem>0)
			{
				if(rem%2==0)
					v[l].pb(kg);
				else
					v[r].pb(kg);
				kg++;
				rem--;
			}
		/*	F(i,1,div+1)
			{
				v[i].pb(i+1);
				
			}
			l = div+1;
			F(i,div+2,2*div+2)
			{
				v[i].pb(i+1);
			}
			d = div+2;
			F(i,2*div+3,3*div+3)
			{
				v[i].pb(i+1);
			}
			r = 2*div+3;
			t = n;
			
			v[t].pb(l);
			v[t].pb(r);
			v[d].pb(l);
			v[d].pb(r);
			//ans*/
			cout<<n<<endl;
			F(i,1,n+1)
			{
				F(j,0,v[i].size())
				{
					cout<<i<<" "<<v[i][j]<<endl;
				}
			}
			cout<<"1"<<endl;
			
		}
		
	}
}
