#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%ld",&x)
#define li long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
using namespace std;

int parent[100500],size[100500],minparent_tax[100500];

void mintax(int tax,int i)
{
	if(tax<minparent_tax[i] && tax>=0)
		minparent_tax[parent[i]]=tax;
}
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
	int n,m;
	s(n),s(m);
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
	int tax[n];
	for(int i=1;i<=n;i++)
	{
		s(tax[i]);
	}
	for(int i=1;i<=n;i++)
	{
		minparent_tax[i] = tax[findparent(i)];
	}
	for(int i=1;i<=n;i++)
	{
		mintax(tax[i],i);
	}
	long long ans=0;
	int cnt1=0,cnt2=0,minm=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		if(parent[i]==i)
			cnt1++;
		if(parent[i]==i &&minparent_tax[i]>=0)
		{
			if(minm>minparent_tax[i])
				minm=minparent_tax[i];
			ans+=minparent_tax[i];
			cnt2++;
	}}
	ans+=minm*(cnt1-2);
	if(cnt1!=cnt2)
		printf("-1\n");
	else
		printf("%lld\n",ans*1ll);
}
