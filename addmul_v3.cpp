#include<iostream>
#include<algorithm>
using namespace std;
 
#include<string.h>
#include<math.h> 
 #define sl(x) scanf("%lld",&x)
#define lli long long
#define s(x) scanf("%d",&x)
#define MOD 1000000007
 
long long arr[105500];
long long tree[890500];
long long lazy[890500][2];


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
			tree[node] = (tree[node]+(b-a+1)*lazy[node][0])%MOD;
			if(a != b) {
			if(lazy[2*node][0]!=0)
    		{
    			int fl = lazy[2*node][1];
    			if(fl==2)
    			{
    				update_tree(node*2, a, (a+b)/2, i, j, lazy[node][0],lazy[2*node][1],1);
    				lazy[node*2][0] = lazy[node][0];
    				lazy[node*2][1]=1;
    			}
    			else 
    				{//cout<<"sas";
    				lazy[2*node][0] =(lazy[2*node][0]+lazy[node][0])%MOD;}
    		}
    		else
    		{
    			lazy[node*2][0] = lazy[node][0]%MOD;
    			lazy[node*2][1] = 1;
    			//cout<<"sas";
    		}
    		if(lazy[node*2+1][0]!=0)
    		{
    			int fl = lazy[2*node+1][1];
    			if(fl==2)
    			{
    				update_tree(1+node*2, 1+ (a+b)/2,b, i, j, lazy[node][0],lazy[2*node+1][1],1);
    				lazy[node*2+1][0] = lazy[node][0];
    				lazy[node*2+1][1]=1;
    			}
    			else
    			{
    			//cout<<"sas";
    				lazy[2*node+1][0] =(lazy[2*node+1][0]+lazy[node][0])%MOD;}
    		}
    		else
    		{
    			lazy[node*2+1][0] = lazy[node][0]%MOD;
    			lazy[node*2+1][1]=1;
    		}
		}
		
		}
		else if(lazy[node][1]==2)
		{
			tree[node] =(tree[node]*lazy[node][0])%MOD;
			if(a != b) {
			if(lazy[2*node][0]!=0)
    		{
    			if(lazy[2*node][1]==1)
    			{
    				update_tree(node*2, a, (a+b)/2, i, j, lazy[node][0],lazy[2*node][1],1);
    				lazy[node*2][0] = lazy[node][0];
    				lazy[node*2][1]=2;
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
    				update_tree(1+node*2, 1+ (a+b)/2,b, i, j, lazy[node][0],lazy[2*node+1][1],1);
    				lazy[node*2+1][0] = lazy[node][0];
    				lazy[node*2+1][1]=2;
    			}
    			else
    			lazy[2*node+1][0] =(lazy[2*node+1][0]*lazy[node][0])%MOD;
    		}
    		else
    		{
    			lazy[node*2+1][0] = (lazy[node][0])%MOD;
    			lazy[node*2+1][1]=2;
    		}
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
		if(flag==1)
			return;
		
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
    				update_tree(node*2, a, (a+b)/2, i, j, v,lazy[2*node][1],1);
    				lazy[node*2][0] = v;
    				lazy[node*2][1]=1;
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
    				update_tree(1+node*2, 1+ (a+b)/2,b, i, j, v,lazy[2*node+1][1],1);
    				lazy[node*2+1][0] = v;
    				lazy[node*2+1][1]=1;
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
    				update_tree(node*2, a, (a+b)/2, i, j, v,lazy[2*node][1],1);
    				lazy[node*2][0] = v;
    				lazy[node*2][1]=2;
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
    				update_tree(1+node*2, 1+ (a+b)/2,b, i, j, v,lazy[2*node+1][1],1);
    				lazy[node*2+1][0] = v;
    				lazy[node*2+1][1]=2;
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
		if(lazy[node][1]==1)
		{
			tree[node] = (tree[node]+(b-a+1)*lazy[node][0])%MOD;
			if(a != b) {
			if(lazy[2*node][0]!=0)
    		{
    			int fl = lazy[2*node][1];
    			if(fl==2)
    			{
    				update_tree(node*2, a, (a+b)/2, i, j, lazy[node][0],lazy[2*node][1],1);
    				lazy[node*2][0] = lazy[node][0];
    				lazy[node*2][1]=1;
    			}
    			else 
    				{//cout<<"sas";
    				lazy[2*node][0] =(lazy[2*node][0]+lazy[node][0])%MOD;}
    		}
    		else
    		{
    			lazy[node*2][0] = lazy[node][0]%MOD;
    			lazy[node*2][1] = 1;
    			//cout<<"sas";
    		}
    		if(lazy[node*2+1][0]!=0)
    		{
    			int fl = lazy[2*node+1][1];
    			if(fl==2)
    			{
    				update_tree(1+node*2, 1+ (a+b)/2,b, i, j, lazy[node][0],lazy[2*node+1][1],1);
    				lazy[node*2+1][0] = lazy[node][0];
    				lazy[node*2+1][1]=1;
    			}
    			else
    			{
    			//cout<<"sas";
    				lazy[2*node+1][0] =(lazy[2*node+1][0]+lazy[node][0])%MOD;}
    		}
    		else
    		{
    			lazy[node*2+1][0] = lazy[node][0]%MOD;
    			lazy[node*2+1][1]=1;
    		}
		}
		
		}
		else if(lazy[node][1]==2)
		{
			tree[node] =(tree[node]*lazy[node][0])%MOD;
			if(a != b) {
			if(lazy[2*node][0]!=0)
    		{
    			if(lazy[2*node][1]==1)
    			{
    				update_tree(node*2, a, (a+b)/2, i, j, lazy[node][0],lazy[2*node][1],1);
    				lazy[node*2][0] = lazy[node][0];
    				lazy[node*2][1]=2;
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
    				update_tree(1+node*2, 1+ (a+b)/2,b, i, j, lazy[node][0],lazy[2*node+1][1],1);
    				lazy[node*2+1][0] = lazy[node][0];
    				lazy[node*2+1][1]=2;
    			}
    			else
    			lazy[2*node+1][0] =(lazy[2*node+1][0]*lazy[node][0])%MOD;
    		}
    		else
    		{
    			lazy[node*2+1][0] = (lazy[node][0])%MOD;
    			lazy[node*2+1][1]=2;
    		}
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
		
	}

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
  	}
}
