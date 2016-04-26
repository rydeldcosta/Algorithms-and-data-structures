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
		int n,m,z,l,r,i,j;
		lli b;
		s(n),s(m),s(z),s(l),s(r),sl(b);
		int seats[n];
		F(i,0,n)
			seats[i]=m;
		int rw=0,count=0;
		while(l>0 || r>0)
		{
			if(l>0)
			{
				if(seats[rw]>1)
				{
				//	cout<<"l";
					seats[rw]--;
					count++;
					l--;
				}
				else
				{
					rw++;
					continue;
				}
			}
			if(r>0)
			{
				if(seats[rw]>1)
				{
				//	cout<<"r";
					seats[rw]--;
					count++;
					r--;
				}
				else
				{
					rw++;
					continue;
				}
			}
		}
			for(i=0;i<n && b>0;i++)
			{
				//cout<<"b";
				
				int x = min((lli)(seats[i]+1)/2,b);
				count+=x;
				seats[i]-=x;
				b-=x;
			}
			count = min(count+z,n*m);
			printf("%d\n",count);
			
		
	}
}
