#include<bits/stdc++.h>

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%ld",&x)
#define lli long long int
#define MOD 1000000000

using namespace std;

lli C[2500][2500], dp[5000][5000];
int n,m;

void precompute()
{
	int i,j;
	for(i=0;i<2500;i++)
	{
		C[i][0] = 1;
		C[i][1] = i;
	}
	for(i=2;i<=2500;i++)
	{
		for(j=2;j<=i;j++)
		{
			C[i][j]=(C[i-1][j] +MOD+ C[i-1][j-1])%MOD;
		}
	}
	//ncr = n-1cr + n-1cr-1
}
int solve(int i,int x)
{

	lli sum=0;
	for(int j =1;j<=n;j++)
	{
		sum=0;
	//	for(int k=0;k<=m;k++)
			
		for(int k=0;k<=m;k++)
		{
			sum+=dp[j-1][k];
			if(sum>MOD){
				sum-=MOD;
			}
			dp[j][k] += (sum*C[k+m-1][m-1])%MOD+MOD;
			dp[j][k]%=MOD; 
		}
	}
	lli ans=0;
	for(int j=0;j<=m;j++){
	
		ans=(dp[n][j]+MOD+ans)%MOD;
	//	ans%=MOD;
		}
	return ans;
}


int main()
{
	precompute();
	int t;
	s(t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		s(n),s(m);
		dp[0][0]=1;
		//for(int i=1;i<=n;i++)
		//	dp[i][0]=1;
		
		cout<<solve(n,m)<<endl;
		
	}
}
