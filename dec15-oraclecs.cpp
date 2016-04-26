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
		int n,m;
		s(n);
		char arr[n][105];
		int as=INT_MAX,bs=INT_MAX;
		for(int i=0;i<n;i++)
		{
			int j,cnt=0;
			scanf("%s", arr[i]);
			m = strlen(arr[i]);
			for(int j=0;j<m;j++)
			
			{
				//scanf("%c", &arr[i][j]);
				if(arr[i][j]=='a')
					cnt++;
			}
			as = min(as,cnt);
			bs = min(bs,m-cnt); 
		//	cout<<"d";
		}
		int ans;
		if(as==0 || bs==0)
			ans=0;
		else
		{
		
		int iaa,iab,iba,ibb;
		iaa = m-as;
		iab = as;
		iba = bs;
		ibb = m-bs;
		as = min(min(iba,as),min(iaa,as));
		bs = min(min(iab,bs),min(ibb,bs));
		
		ans=min(bs,as);
	}
		printf("%d\n",ans);
	}
} 
