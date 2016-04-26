//DP bits

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

int dp[2][1025];

/*int bintodec(lli x)
{
	int num = 0,i=1;
	while(x)
	{
		num += (x%10)*i;
		i*=2;
		x/=10;
	}
	return num;
}*/
int main()
{
	int t;
	s(t);
	while(t--)
	{
		char s[11];
		scanf("%s",s);
		int n;
		s(n);
		int i=1,j;
		lli num=0,num2=0;
		for(j=9;j>=0;j--)
			{
				if(s[j]=='w')
					num += 1*i;
				i*=2;
			}
			
		int x[n+2];
	//	num2=0;
		F(i,0,n)
		{
			char filt[11];
			scanf("%s",filt);
			num2=0;
			int k=1;
			for(j=9;j>=0;j--)
			{
				if(filt[j]=='+')
					num2+=k;
				k*=2;
			}
			x[i] = num2;
		}
		
		
		int dp[2][1025];
		F(i,0,1024)
			dp[0][i]=0;
		dp[0][0]=1;
		for(i=1;i<=n;i++){
			int a = x[i-1];
			for(j=0;j<1024;j++){
				dp[1][j] = dp[0][j] + dp[0][j^a];
				if(dp[1][j]>=MOD)
					dp[1][j] -= MOD;
				
			}
			for(j=0;j<1024;j++)
				dp[0][j] = dp[1][j];
		}
		printf("%d\n",dp[1][num]);
	
	}
}
