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
//lli hash[1000005][3];
int main()
{
	int t;
	s(t);
	int i,j;
	
	while(t--)
	{
		int n,x;
		s(n),s(x);
		lli m,arr[n+5];
		sl(m);
		lli hash[3][x+1];
		F(i,1,x+1)
			hash[1][i]=1;
		hash[2][1]=1;
		m%=MOD;
		F(i,1,n+1)
		{
			sl(arr[i]);
			arr[i]%=MOD;
		}
		if(x<=2)
		{
			if(x==1)
				printf("%lld\n",arr[1]%MOD);
			else
				printf("%lld\n", (lli)(arr[2]%MOD+(arr[1])%MOD*(m))%MOD);
			
		}
		else{
		
		F(i,1,m)
		{
			F(j,1,x+1)
			{
				if(j==1)
					hash[2][j] = 1;
				else
				hash[2][j] = hash[1][j] + hash[2][j-1];
				if(hash[2][j]>=MOD)
					hash[2][j]-=MOD;
					
				hash[1][j] =hash[2][j];
			}
		}	
//		F(i,1,n+1)
//			cout<<hash[2][i]<<" ";
		j=1;
		lli ans=0;
		for(i=x;i>=1;i--)
		{
			ans = ans + (((arr[i])%MOD)*hash[2][j])%MOD;
			if(ans>=MOD)
				ans-=MOD;
			j++;
		}
		if(m==0)
			printf("%lld\n",arr[x]%MOD);
		else
			printf("%lld\n",ans%MOD);
	}
	}
}   
