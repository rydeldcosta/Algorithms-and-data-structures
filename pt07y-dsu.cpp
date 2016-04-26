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
int findparent(int i)
{
	if(parent[parent[i]]!=parent[i])
		parent[i] =  findparent(parent[i]);
	return parent[i];
}
bool union_nodes(int a,int b)
{
	if(parent[a]==parent[b])
		return false;
	int par_a,par_b;
	par_a=findparent(a),par_b=findparent(b);
	if(size[a]>size[b])
	{
		size[a]+=size[b];
	//	size[b]=size[a];
		parent[par_b]=par_a;
	}
	else
	{
		size[b]+=size[a];
	//	size[a]=size[b];
		parent[par_a]=par_b;
	}
	return true;
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
	for(int i=1;i<=m;i++)
	{
		int a,b;
		s(a),s(b);
		if(!union_nodes(a,b))
		{
		//	cout<<"sama";
			flag=0;
			cout<<"NO\n";
			break;
		}
	}
	int count =0;
	if(flag==0) return 0;
	for(int i=1;i<=n;i++)
	{
		if(parent[i]==i)
		{
			count++;
			if(count>1)
			{
				flag=0;
		//	cout<<"saa"<<i;
			cout<<"NO\n";
			break;
			}
		
		}
	}
	if(flag==1)
		cout<<"YES\n";
	
}
