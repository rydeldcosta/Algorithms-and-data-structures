#include<iostream>
#include<algorithm>
using namespace std;
 
#include<string.h>
#include<math.h> 
 #define sl(x) scanf("%lld",&x)
#define lli long long
#define s(x) scanf("%d",&x)
#define MOD 1000000007
#define mod 101
 
long long arr[105500];
long long tree[890500];
long long lazy[890500][2];
double hash[890500];
lli key;


void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    		tree[node] = arr[a]%MOD; // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] = (tree[node*2]+ tree[node*2+1])%MOD; // Init root value
	
}

void update_tree(int node, int a, int b, int i, int j, long long v,int f,int flag) {
	
		if(lazy[node][0] != 0) { 
		if(lazy[node][1]==1)
		{
			tree[node] = (tree[node]+(b-a+1)*lazy[node][0]);
			tree[node]%=MOD;
			//hash[node%mod]=0;
			if(a != b) {
			if(lazy[2*node][0]!=0)
    		{
    			int fl = lazy[2*node][1];
    			if(fl==2)
    			{
    				//hash[(2*node)%mod] = hash[node%mod];
    				hash[2*node] = ((double)lazy[2*node][0]*2/(b-a+1)+(double)lazy[node][0]/tree[2*node]);
    				//lazy[2*node][0]%=MOD;
    				lazy[2*node][1]=2;
    			}
    			else
    				lazy[2*node][0] =(lazy[2*node][0]+lazy[node][0])%MOD;
    		}
    		else
    		{
    			lazy[node*2][0] = lazy[node][0]%MOD;
    			lazy[node*2][1] = 1;
    			
    		}
    		if(lazy[node*2+1][0]!=0)
    		{
    			int fl = lazy[2*node+1][1];
    			if(fl==2)
    			{
    				//hash[(2*node+1)%mod] = hash[node%mod];
    				hash[2*node+1] = ((double)lazy[2*node+1][0]*2/(b-a+1)+(double)lazy[node][0]/tree[2*node+1]);
    				//lazy[2*node][0]%=MOD;
    				lazy[2*node+1][1]=2;
    			}
    			else
    				lazy[2*node+1][0] =(lazy[2*node+1][0]+lazy[node][0])%MOD;
    		}
    		else
    		{
    			lazy[node*2+1][0] = (lazy[node][0])%MOD;
    			lazy[node*2+1][1]=1;
    		}
		
		}}
		else if(lazy[node][1]==2)
		{
			if(hash[node]!=0)
			{
				tree[node] =(lli)(tree[node]*(b-a+1)*hash[node]);
				tree[node]%=MOD;
				cout<<"cc"<<tree[node]<<endl;
			}
			else
			tree[node] =(tree[node]*lazy[node][0])%MOD;
		//	hash[node%mod] = 0;		//reset
			if(a != b) {
			if(lazy[2*node][0]!=0)
    		{
    			if(lazy[2*node][1]==1)
    			{
    				//hash[(2*node)%mod] = hash[node%mod];
    				hash[2*node] = ((double)hash[node]*2/(b-a+1)+(double)lazy[2*node][0]*hash[node]/tree[2*node]);
    				//lazy[2*node][0]%=MOD;
    				lazy[2*node][1]=2;
    			}
    			else
    				lazy[2*node][0] =(lazy[2*node][0]*lazy[node][0])%MOD;
    		}
    		else
    		{
    			lazy[node*2][0] = lazy[node][0]%MOD;
    			lazy[node*2][1] = 2;
    			
    		}
    		if(lazy[node*2+1][0]!=0)
    		{
    			if(lazy[2*node+1][1]==1)
    			{
    				//hash[(2*node+1)%mod] = hash[node%mod];
    				hash[2*node+1] = ((double)hash[node]*2/(b-a+1)+(double)lazy[2*node+1][0]*hash[node]/tree[2*node+1]);
    				
    				//lazy[2*node+1][0]%=MOD;
    				lazy[2*node+1][1] = 2;
    			}
    			else
    				lazy[2*node+1][0] =(lazy[2*node+1][0]*lazy[node][0])%MOD;
    		}
    		else
    		{
    			lazy[node*2+1][0] = (lazy[node][0])%MOD;
    			lazy[node*2+1][1]=2;
    		}
    		hash[node]=0;
		}
		
		}
		else if(lazy[node][1]==3)
		{
			tree[node] =((b-a+1)*lazy[node][0])%MOD;
			if(a != b) {
				lazy[node*2][0] = lazy[node][0]%MOD;
    			lazy[node*2][1] = 3;
				lazy[node*2+1][0] = lazy[node][0]%MOD;
    			lazy[node*2+1][1]=3;
			
		
		}}
		lazy[node][0]=0;
		lazy[node][1]=0;
		hash[node%mod] = 0;
	}
    if(f==1)
    {
  
    	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >=i && b<=j){ 
    		tree[node] += v*(b-a+1);				//heres the change :)
    		tree[node]%=MOD;
    		if(a != b) { // Not leaf node
    		if(lazy[2*node][0]!=0)
    		{
    			int fl = lazy[2*node][1];
    			if(fl==2)
    			{
    				//hash[(2*node)%mod] = v;
    				hash[2*node] = ((double)lazy[2*node][0]*2/(b-a+1)+(double)v/tree[2*node]);
    				cout<<hash[2*node]<<"Ss"<<endl;
    				//lazy[2*node][0]%=MOD;
    				lazy[2*node][1]=2;
    			}
    			else
    				lazy[2*node][0] =(lazy[2*node][0]+v)%MOD;
    		}
    		else
    		{
    			lazy[node*2][0] = v%MOD;
    			lazy[node*2][1] = 1;
    			
    		}
    		if(lazy[node*2+1][0]!=0)
    		{
    			int fl = lazy[2*node+1][1];
    			if(fl==2)
    			{
    				//hash[(2*node+1)%mod] = v;
    				hash[2*node+1] = ((double)lazy[2*node+1][0]*2/(b-a+1)+(double)v/tree[2*node+1]);
    				//lazy[2*node][0]%=MOD;
    			//	cout<<hash[2*node+1]<<"Ss"<<endl;
    				lazy[2*node+1][1]=2;
    			}
    			else
    				lazy[2*node+1][0] =(lazy[2*node+1][0]+v)%MOD;
    		}
    		else
    		{
    			lazy[node*2+1][0] = (v)%MOD;
    			lazy[node*2+1][1]=1;
    		}
    	
		}
    		return;
	}
 
	update_tree(node*2, a, (a+b)/2, i, j, v,f,0); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, v,f,0); // Updating right child
 
	tree[node] = (tree[node*2] + tree[node*2+1])%MOD; // Updating root with max value
    }
    else if(f==2)
    {
    	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >=i && b<=j) { // Leaf node
    		tree[node] = (tree[node]*v)%MOD;
    		//tree[node]%=MOD;
    		if(a != b) { // Not leaf node
    		if(lazy[2*node][0]!=0)
    		{
    			if(lazy[2*node][1]==1)
    			{
    			//	hash[(2*node)%mod] = v;
    				hash[2*node] = ((double)v*2/(b-a+1)+(double)lazy[2*node][0]*v/tree[2*node]);
    				//lazy[2*node][0]%=MOD;
    				lazy[2*node][1]=2;
    			//	cout<<hash[2*node]<<"aa"<<endl;
    			}
    			else
    				lazy[2*node][0] =(lazy[2*node][0]*v)%MOD;
    		}
    		else
    		{
    			lazy[node*2][0] = v%MOD;
    			lazy[node*2][1] = 2;
    			
    		}
    		if(lazy[node*2+1][0]!=0)
    		{
    			if(lazy[2*node+1][1]==1)
    			{
    				//hash[(2*node+1)%mod] = v;
    				hash[2*node+1] = ((double)v*2/(b-a+1)+(double)lazy[2*node+1][0]*v/tree[2*node+1]);
    				
    				//lazy[2*node+1][0]%=MOD;
    				lazy[2*node+1][1] = 2;
    			//	cout<<hash[2*node+1]<<"aa"<<endl;
    			}
    			else
    				lazy[2*node+1][0] =(lazy[2*node+1][0]*v)%MOD;
    		}
    		else
    		{
    			lazy[node*2+1][0] = (v)%MOD;
    			lazy[node*2+1][1]=2;
    		}
		}
    		return;
	}
 
	update_tree(node*2, a, (a+b)/2, i, j, v,f,0); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, v,f,0); // Updating right child
 
	tree[node] = (tree[node*2]+ tree[node*2+1])%MOD; 
    }
    else if(f==3)
    {
    	
    	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >=i && b<=j) { // Leaf node
    		tree[node] = (v*(b-a+1))%MOD;
    		if(a != b) { // Not leaf node
    		lazy[node*2][0] = v%MOD;
    		lazy[node*2][1] = 3;
    		lazy[node*2+1][0] = (v)%MOD;
    		lazy[node*2+1][1]=3;
		}
    		return;
	}
 
	update_tree(node*2, a, (a+b)/2, i, j, v,f,0); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, v,f,0); // Updating right child
 
	tree[node] = (tree[node*2]+ tree[node*2+1])%MOD; 
    }
	
}



long long query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return 0; // Out of range
	if(lazy[node][0] != 0) { 
		if(lazy[node][0] != 0) { 
		if(lazy[node][1]==1)
		{
			tree[node] = (tree[node]+(b-a+1)*lazy[node][0]);
			tree[node]%=MOD;
			//hash[node%mod]=0;
			if(a != b) {
			if(lazy[2*node][0]!=0)
    		{
    			int fl = lazy[2*node][1];
    			if(fl==2)
    			{
    				//hash[(2*node)%mod] = hash[node%mod];
    				hash[2*node] = ((double)lazy[2*node][0]*2/(b-a+1)+(double)lazy[node][0]/tree[2*node]);
    				//lazy[2*node][0]%=MOD;
    				lazy[2*node][1]=2;
    			}
    			else
    				lazy[2*node][0] =(lazy[2*node][0]+lazy[node][0])%MOD;
    		}
    		else
    		{
    			lazy[node*2][0] = lazy[node][0]%MOD;
    			lazy[node*2][1] = 1;
    			
    		}
    		if(lazy[node*2+1][0]!=0)
    		{
    			int fl = lazy[2*node+1][1];
    			if(fl==2)
    			{
    				//hash[(2*node+1)%mod] = hash[node%mod];
    				hash[2*node+1] = ((double)lazy[2*node+1][0]*2/(b-a+1)+(double)lazy[node][0]/tree[2*node+1]);
    				//lazy[2*node][0]%=MOD;
    				lazy[2*node+1][1]=2;
    			}
    			else
    				lazy[2*node+1][0] =(lazy[2*node+1][0]+lazy[node][0])%MOD;
    		}
    		else
    		{
    			lazy[node*2+1][0] = (lazy[node][0])%MOD;
    			lazy[node*2+1][1]=1;
    		}
		
		}}
		else if(lazy[node][1]==2)
		{
			if(hash[node]!=0)
			{
				tree[node] =(lli)(tree[node]*(b-a+1)*hash[node]);
				tree[node]%=MOD;
			}
			else
			tree[node] =(tree[node]*lazy[node][0])%MOD;
		//	hash[node%mod] = 0;		//reset
			if(a != b) {
			if(lazy[2*node][0]!=0)
    		{
    			if(lazy[2*node][1]==1)
    			{
    				//hash[(2*node)%mod] = hash[node%mod];
    				hash[2*node] = ((double)hash[node]*2/(b-a+1)+(double)lazy[2*node][0]*hash[node]/tree[2*node]);
    				//lazy[2*node][0]%=MOD;
    				lazy[2*node][1]=2;
    			}
    			else
    				lazy[2*node][0] =(lazy[2*node][0]*lazy[node][0])%MOD;
    		}
    		else
    		{
    			lazy[node*2][0] = lazy[node][0]%MOD;
    			lazy[node*2][1] = 2;
    			
    		}
    		if(lazy[node*2+1][0]!=0)
    		{
    			if(lazy[2*node+1][1]==1)
    			{
    				//hash[(2*node+1)%mod] = hash[node%mod];
    				hash[2*node+1] = ((double)hash[node]*2/(b-a+1)+(double)lazy[2*node+1][0]*hash[node]/tree[2*node+1]);
    				
    				//lazy[2*node+1][0]%=MOD;
    				lazy[2*node+1][1] = 2;
    			}
    			else
    				lazy[2*node+1][0] =(lazy[2*node+1][0]*lazy[node][0])%MOD;
    		}
    		else
    		{
    			lazy[node*2+1][0] = (lazy[node][0])%MOD;
    			lazy[node*2+1][1]=2;
    		}
    		hash[node]=0;
		}
		
		}

		else if(lazy[node][1]==3)
		{
			tree[node] =((b-a+1)*lazy[node][0])%MOD;
			if(a != b) {
				lazy[node*2][0] = lazy[node][0]%MOD;
    			lazy[node*2][1] = 3;
				lazy[node*2+1][0] = lazy[node][0]%MOD;
    			lazy[node*2+1][1]=3;
			
		
		}}
		lazy[node][0]=0;
		lazy[node][1]=0;
		
	}}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
	{
		return (tree[node])%MOD;
}
	long long q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	long long q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
 
	long long res = (q1+q2); // Return final result
	
	return res%MOD;
}
 
int main() {
	long long num,q;
	scanf("%lld %lld",&num,&q);
//	memset(lazy,0,sizeof lazy);
	for(long long i=1;i<=num;i++)
	{
		sl(arr[i]);
	}
	build_tree(1, 1, num);
	long long x,y,v,f;
  	for(int i=0;i<q;i++)
  	{
  		
  	
  		sl(f),sl(x),sl(y);
  	
  		if(f==4)
  		{

  			printf("%lld\n",query_tree(1,1,num,x,y));
  		}
  		else
  		{
  			
  			sl(v);

  			update_tree(1,1,num,x,y,v,f,0);
  		}
  		for(long long i=1;i<=2*num-1;i++)
{
		cout<<tree[i]<<" ";
}
	cout<<endl;
		for(long long i=1;i<=2*num-1;i++)
{
		cout<<lazy[i][0]<<" ";
	}
	cout<<endl;
	for(long long i=1;i<=2*num-1;i++)
{
		cout<<hash[i]<<" ";
	}
	cout<<endl;
  	}
}
