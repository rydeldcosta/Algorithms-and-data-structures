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


void solve(int arr[],int n, int k)
{
	int dp[k+1][k+1];
	int i,j,x;
	int z=0,mi=INT_MAX;
	F(i,1,k+1)
	{
		if(arr[i]==-1)
			dp[1][i] = INT_MAX;
		else
			dp[1][i] = arr[i];
	}
	F(i,2,n+1)
	{
		F(j,1,k+1)
		{
			mi = INT_MAX;
			for(z=1;z<=j;z++)
			{
				if(z==j && arr[z]!=-1)
					mi=min(mi,arr[z]);
				//if(dp[i-1][j-z]!=-1)
				else if(arr[z]!=-1 && dp[i-1][j-z]!=INT_MAX)
					mi = min(mi,arr[z]+dp[i-1][j-z]);
			}
		//	if(dp[i-1][j]!=-1)
				dp[i][j]= min(mi,dp[i-1][j]);
		//	else if(mi==INT_MAX)
		//		dp[i][j] = -1;
		//	else
		//		dp[i][j]=mi;	
			
		}
	}
	if(dp[n][k]==INT_MAX)
		printf("-1\n");
	else
		printf("%d\n", dp[n][k]);
	/*F(i,1,n+1){
	
		F(j,1,k+1)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;}*/
}

int main()
{
	int t;
	s(t);
	while(t--)
	{
		int n,k;
		s(n),s(k);
		int i;
		int arr[k+5];
		F(i,1,k+1)
			s(arr[i]);
		
		solve(arr,n,k);
	}
}
