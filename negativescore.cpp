
#include<iostream>
#include<algorithm>
using namespace std;
 
#include<string.h>
#include<math.h> 
 

#define MAX (1+(1<<6)) // Why? :D
//#define inf 0x7fffffff
 
long long arr[100050];
long long tree[MAX];
long long lazy[MAX];
 
/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	if(tree[2*node]>tree[2*node+1])
		tree[node] = tree[2*node+1];
	else
		tree[node] = tree[2*node];
	//tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}
 

 
/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return INT_MAX; // Out of range
 
 
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];
 
	long long q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	long long q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
 	
	long long res = min(q1, q2); // Return final result
	
	return res;
}
 
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(tree,0,sizeof(tree));
	int N,q;
	scanf("%d %d",&N,&q);
	
	for(int i = 1; i <= N; i++) 
 	{
 		scanf("%lld",&arr[i]);
 	}
	build_tree(1, 1, N);
 	for(int i=1;i<2*N+1;i++)
 	{
 		cout<<tree[i]<<" ";
 	}

	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%lld\n",query_tree(1, 1, N, a, b));
	} 
	//cout << query_tree(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
}
}
