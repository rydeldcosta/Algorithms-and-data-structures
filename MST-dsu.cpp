#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%ld",&x)
#define li long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mod 1000000007
using namespace std;
int parent[100500],size[100500];
vector<struct node> vec;
int mst;
struct node
{
	int x,y,weight;
};
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
bool cmp(struct node a, struct node b)
{
	return a.weight<b.weight;
}
int main()
{
	
	int n,m,flag=1;
	s(n),s(m);
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
		size[i]=1;
	}
	int f,g,h;
	struct node tmp;
	for(int i=1;i<=n;i++)
	{
		s(f),s(g),s(h);
		tmp.x=f;
		tmp.y=g;
		tmp.weight=h;
		vec.pb(tmp);
		
	}
	sort(all(vec),cmp);
	for(int i=0;i<n;i++)
	{
		union_nodes(vec[i].x,vec[i].y,i);
	}
	cout<<mst<<endl;
	
	
	
}
