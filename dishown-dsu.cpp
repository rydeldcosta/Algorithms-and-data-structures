#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define li long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
using namespace std;

long long parent[100500],size[100500];
long long ar[100500];

long long findparent(long long i)
{
	if(parent[parent[i]]!=parent[i])
		parent[i] =  findparent(parent[i]);
	return parent[i];
}
bool union_nodes(long long a,long long b)
{

	long long par_a,par_b;
	par_a=findparent(a),par_b=findparent(b);
	if(par_a==par_b)
		return false;
	if(ar[a]>ar[b])
	{
		size[a]+=size[b];
		parent[par_b]=par_a;
			return true;
	}
	else if(ar[a]<ar[b])
	{
		size[b]+=size[a];
		parent[par_a]=par_b;
			return true;
	}
	else
		return true;
}
int main()
{
	int t;
	s(t);
	while(t--)
	{
		memset(parent,0,sizeof(parent));
		memset(size,0,sizeof(size));
		memset(ar,0,sizeof(ar));
		long long n;
		sl(n);
		for(int i=1;i<=n;i++)
		{
		parent[i]=i;
		size[i]=1;
		}
	//	int ar[n+10];
		for(int i=1;i<=n;i++)
		{
			sl(ar[i]);
		}
		long long q;
		sl(q);
		for(int i=1;i<=q;i++)
		{
			long long f,d,e;
			sl(f);
			if(f==0)
			{
				sl(d),sl(e);
				if(!union_nodes(d,e))
					printf("Invalid query!\n");
			}
			else if(f==1)
			{
				sl(d);
				printf("%lld\n",findparent(d));
				
			}
		}
	}
	
}
