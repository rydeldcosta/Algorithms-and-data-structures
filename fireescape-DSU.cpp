#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%ld",&x)
#define li long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mod 1000000007
using namespace std;

//li C[25000][25000];
int parent[100500],size[100500];
/*void precompute()
{
	int i,j;
	for(i=0;i<25000;i++)
	{
		C[i][0] = 1;
		C[i][1] = i;
	}
	for(i=2;i<=25000;i++)
	{
		for(j=2;j<=i;j++)
		{
			C[i][j]=(C[i-1][j] +mod+ C[i-1][j-1])%mod;
		}
	}
}*/
int findparent(int i)
{
	if(parent[parent[i]]!=parent[i])
		parent[i] =  findparent(parent[i]);
	return parent[i];
}
void union_nodes(int a,int b)
{
	if(parent[a]==parent[b])
		return;
	int par_a,par_b;
	par_a=findparent(a),par_b=findparent(b);
	if(par_a==par_b)
		return;
	if(size[a]>size[b])
	{
		size[a]+=size[b];
		parent[par_b]=par_a;
	}
	else
	{
		size[b]+=size[a];
		parent[par_a]=par_b;
	}
	return;
}

int main()
{
	int t;
	s(t);
	while(t--)
	{
		memset(parent,0,sizeof(parent));
		memset(size,0,sizeof(size));
		int n,m;
		s(n),s(m);
		if(m==0)
		{
			cout<<1ll*n<<" "<<"1"<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
		parent[i]=i;
		size[i]=1;
		}
		for(int i=1;i<=m;i++)
		{
		int a,b;
		s(a),s(b);
		union_nodes(a,b);
		}
		long long cnt=0,cnt2=1;
		for(int i=1;i<=n;i++)
		{
			if(parent[i]==i)
			{
				cnt++;
				cnt%=mod;
			}
			if(size[i]>1)
				cnt2=((long long)cnt2%mod)*(size[i]%mod)%mod;
		}
		cout<<1ll*cnt%mod<<" "<<(long long)cnt2%mod<<endl;
	}
}
