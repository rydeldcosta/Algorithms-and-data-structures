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
		lli a[n],b[n],c[n];
		for(int i=0;i<n;i++)
		{
			sl(a[i]),sl(b[i]),sl(c[i]);
		}
		int cnt = INT_MIN,cnt1=0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				float as,bs,cs;
				
				if(a[j]==0)
				{
					as=-1;
					if(a[i]==0)
						as=1;
				}
				else
					as = (double)a[i]/a[j];
				if(b[j]==0)
				{
					bs=-1;
					if(b[i]==0)
						bs=1;
				}
				else
					bs = (double)b[i]/b[j];
				if(c[j]==0)
				{
					cs=-1;
					if(c[i]==0)
						cs=1;
				}
				else
					cs = (double)c[i]/c[j];
				if(as==bs && bs!=cs)
					{
						cnt1++;
						cout<<as<<" "<<bs<<" "<<cs<<endl;
							cout<<i<<" "<<j<<endl;
					}
					
			}
			if(cnt1>cnt)
			{
				cnt = cnt1;
					
			}
					cnt1=0;
		}
		printf("%d\n",cnt);
	}
}
