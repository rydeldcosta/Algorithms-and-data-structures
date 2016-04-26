#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define S(x) scanf("%d",&x)
#define lli long long int
#define MAX (1+(1<<6)) // Why? :D
#define inf 0x7fffffff
 #define t 0	//tails
 #define h 1	//heads
 #define debug() printf("debug\n")
//int arr[N];
int tree[1005005];
int lazy[1005005];


int flip(int x)
{
	if(x==1)return 0;
	else return 1;
}
void build_tree(int node, lli a, lli b)
{
	if(a>b)
		return;
	if(a==b){			//leaf node
		tree[node] = t;			//tails initially
		return;
	}
	lli mid = (a+b)/2;
	build_tree(2*node,a,mid);
	build_tree(2*node+1,mid+1,b);
	
	tree[node] = tree[2*node] + tree[2*node+1];		// intialize root
	
}
void update_tree(int node, lli a, lli b, int i, int j)
{
	
	if(lazy[node]!=0)//need to update
	{
			tree[node] = b-a+1-tree[node];		//heads = nodes - tails
		if(a!=b)	//internal node
		{
		
			lazy[2*node]+=1-lazy[2*node];		//flag children
			lazy[2*node+1]+=1-lazy[2*node+1];
		}
		lazy[node]=0;	//reset
	}
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
	
	if(a>=i && b<=j)		//complete in range
	{
		tree[node] = b-a+1-tree[node];		//heads = nodes - tails
		if(a!=b)	//internal node
		{
		
			lazy[2*node]+=1-lazy[2*node];		//flag children
			lazy[2*node+1]+=1-lazy[2*node+1];
		}
		return;
	}
	lli mid = (a+b)/2;
	update_tree(2*node,a,mid,i,j);		// calc for children
	update_tree(2*node+1,mid+1,b,i,j);
	
	tree[node] = tree[2*node] + tree[2*node+1];	//update root
	return;
}
int query(int node, lli a, lli b, int i, int j)
{
	if(lazy[node]!=0)//need to update
	{
		tree[node] += b-a+1-tree[node];		//heads = nodes - tails
		if(a!=b)	//internal node
		{
		
			lazy[2*node]+=1-lazy[2*node];		//flag children
			lazy[2*node+1]+=1-lazy[2*node+1];
		}
		lazy[node]=0;	//reset
	}
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
	
		return 0;				//out of range so returns 0
	if(a>=i && b<=j)		//complete in range
	{
		return tree[node];
	}
	else		// partial overlapping range
	{
		lli mid = (a+b)/2;
		int q1 = query(2*node,a,mid,i,j);
		int q2 = query(2*node+1,mid+1,b,i,j);
		return q1+q2;		//answer
	}
	
}

int main()
{
	lli n,q;
	scanf("%lld %lld", &n,&q);
	memset(lazy,0,sizeof(lazy));
	build_tree(1,0,n-1);		//indexing 1
	while(q--)
	{
		int a,i,j;
		scanf("%d %d %d", &a,&i,&j);
		if(a==1)
		{
			int ans = query(1,0,n-1,i,j);
			printf("%d\n", ans);
		}
		else
		{
			update_tree(1,0,n-1,i,j);
		}
	}
	
	
}
