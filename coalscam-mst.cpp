#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mod 1000000007
using namespace std;

vector<struct node> chef,company;
lli mstch,mstot;
struct node
{
	int x,y;
	lli weight;
};
int findparent(int i,int parent[])
{
	if(parent[parent[i]]!=parent[i])
		parent[i] =  findparent(parent[i],parent);
	return parent[i];
}

void union_nodes2(int a,int b,int i,int parent[],int size[])
{
	if(parent[a]==parent[b])
		return;
	int par_a,par_b;
	par_a=findparent(a,parent),par_b=findparent(b,parent);
	if(par_a==par_b)
		return;
	if(size[a]>size[b])
	{
		size[a]+=size[b];
	
		parent[par_b]=par_a;
	//	mstot+=chef[i].weight;
	
		mstch+=chef[i].weight;
	}
	else
	{
	//	mstot+=chef[i].weight;
	
		mstch+=chef[i].weight;
		size[b]+=size[a];
	
		parent[par_a]=par_b;
	}
	return;
}
void union_nodes1(int a,int b,int i,int parent[],int size[])
{
	if(parent[a]==parent[b])
		return;
	int par_a,par_b;
	par_a=findparent(a,parent),par_b=findparent(b,parent);
	if(par_a==par_b)
		return;
	
	if(size[a]>size[b])
	{
		size[a]+=size[b];
	//	size[b]=size[a];
		parent[par_b]=par_a;
		mstot+=company[i].weight;
		
	}
	else
	{
		mstot+=company[i].weight;
		
		size[b]+=size[a];
	//	size[a]=size[b];
		parent[par_a]=par_b;
	}
	return;
}
bool cmp1(struct node a, struct node b)
{
	return a.weight<b.weight;
}
bool cmp2(struct node a, struct node b)
{
	return a.weight>b.weight;
}
int main()
{
	int t;
	s(t);
	while(t--)
	{
		int parent[100500],size[100500];
		mstch=mstot=0;
		company.clear(),chef.clear();
		int n,m1,m2;
		s(n),s(m1),s(m2);
		for(int i=0;i<n;i++)
		{	
		parent[i]=i;
		size[i]=1;
		}
		int f,g;
		lli h;
		struct node tmp;
		for(int i=1;i<=m1;i++)
		{
			s(f),s(g),sl(h);
			tmp.x=f;
			tmp.y=g;
			tmp.weight=h;
			company.pb(tmp);
		}
	
	//int n,m,flag=1;
	//s(n),s(m);
	sort(all(company),cmp1);
	//int f,g,h;
	//hash[100500]={0};
	for(int i=1;i<=m2;i++)
	{
		s(f),s(g),sl(h);
		tmp.x=f;
		tmp.y=g;
		tmp.weight=h;
	//	hash[(tmp.weight)%101]++; 		//
		chef.pb(tmp);
		
	}
	sort(all(chef),cmp2);
	for(int i=0;i<m2;i++)
	{
		union_nodes2(chef[i].x,chef[i].y,i,parent,size);
	}
	for(int i=0;i<m1;i++)
	{
		union_nodes1(company[i].x,company[i].y,i,parent,size);
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(parent[i]==i)
			cnt++;
	}
	if(cnt>1)
		cout<<"Impossible\n";
	else
		cout<<(lli)mstch<<" "<<(lli)mstot+mstch<<endl;
	
	
	}
}
