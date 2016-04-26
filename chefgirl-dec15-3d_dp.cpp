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

vector<pair<int , pair<int,int> > > v[100005];
int parent[100005],n;
int dp[100002][33][33];
int visited[100005];
int leaf[100005],l=0;
int bestpath[33][33];
int ans[33][33];

void dfs(int ind)
{
	visited[ind]=1;
	if(v[ind].size()==0)
		leaf[l++]=ind;
	for(int i=0;i<v[ind].size();i++)
	{
		int x = v[ind][i].first,y=v[ind][i].second.first,z=v[ind][i].second.second;
		if(!visited[x])
		{
			for(int j=1;j<33;j++)
			{
				for(int k=j;k<33;k++)
				{
					dp[x][j][k] = dp[ind][j][k] + max(0,y-j) + max(0,k-z);
				}
			}
			dfs(x);
		}
	}
	
}
int solve(int left ,int right)
{
	int i,j,k;
	if(left==right)
		return bestpath[left][right];
	else if(ans[left][right]!=-1)
		return ans[left][right];
	else
	{
		int mi=bestpath[left][right];
		for(int i=0;i<right-left;i++)
		{	
			int x = solve(left,left+i) + solve(left+i+1,right);
			mi = min(mi,x);
		}
		ans[left][right] = mi;
		return ans[left][right];
	}
	
	
}
int main()
{
	int m;
	s(n),s(m);
	int i,j,k;
	
	
	F(i,0,m)
	{
		int w,x,y,z;
		s(w),s(x),s(y),s(z);
		v[w].pb(make_pair(x,make_pair(y,z)));
		parent[x] = w;
	}

	F(j,1,33)
	{
		F(k,1,33)
		{
			dp[1][j][k]=0;
		}
	}
	F(i,0,n+1)
	{
		visited[i]=0;
	}
	
	//fills dp[i][j][k]
	dfs(1);
	
	//setting optimum paths
	F(j,1,33)
	{
		F(k,j,33)
		{
			int mi = INT_MAX;
			F(i,0,l)
			{
				int x = leaf[i];
				mi = min(mi,dp[x][j][k]);
			}
			bestpath[j][k] = mi;
		}
	}
/*	F(i,1,33)
	{
		F(j,i,33)
		{
			cout<<bestpath[i][j]<<" ";
		}
		cout<<endl;
	}*/
	F(i,0,33)
	{
		F(j,0,33)
		{
			ans[i][j]=-1;
		}
	}
	printf("%d\n", solve(1,32));
	
	
}
