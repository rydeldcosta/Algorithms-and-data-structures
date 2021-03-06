#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<limits.h>
#include<math.h>
 
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
#define IT(a,it) for(auto it=a.begin(); it != a.end(); it++)
#define REV_IT(a,it) for(auto it=a.rbegin(); it != a.rend(); it++)
#define MAXX 100005
 
using namespace std;
 
typedef pair <int, int> pi_i;
 
int N, Q, arr[MAXX];
int *ST, *lazy;
 
//query with lazy propogation
int queryLazy(int node, int start, int end, int L, int R){
	if(L > end || R < start) return 0;
	if(lazy[node] == 1){	//i.e update curr node if lazy has been set previously
		ST[node] = (end-start+1) - ST[node];
		if(start != end){	//i.e if no leaf then mark children
			lazy[node<<1] = 1-lazy[node<<1];
			lazy[(node<<1)+1] = 1-lazy[(node<<1)+1];
		}
		lazy[node] = 0;
	}
	if(start >= L && end <= R) return ST[node];
	int x = queryLazy(node<<1, start, (start+end)>>1, L, R);
	int y = queryLazy((node<<1)+1, ((start+end)>>1)+1, end, L, R);
return x+y;
}
 
//normal query
int query(int node, int start, int end, int L, int R){
	if(L > end || R < start) return 0;
	if(start >= L && end <= R) return ST[node];
	int x = query(node<<1, start, (start+end)>>1, L, R);
	int y = query((node<<1)+1, ((start+end)>>1)+1, end, L, R);
return x+y;
}
 
void update(int node, int start, int end, int L, int R){
	if(lazy[node] == 1){	//i.e update curr node if lazy has been set previously
		ST[node] = (end-start+1) - ST[node];
		if(start != end){	//i.e if no leaf then mark children
			lazy[node<<1] = 1-lazy[node<<1];
			lazy[(node<<1)+1] = 1-lazy[(node<<1)+1];
		}
		lazy[node] = 0;
	}
	
	if(L > end || R < start) return;
	if(start >= L && end <= R){	//segment inside range hence update
		ST[node] = (end-start+1) - ST[node];
		if(start != end){	//i.e if no leaf then mark children
			lazy[node<<1] = 1-lazy[node<<1];
			lazy[(node<<1)+1] = 1-lazy[(node<<1)+1];
		}
		return;
	}
	
	update(node<<1, start, (start+end)>>1, L, R);
	update((node<<1)+1, ((start+end)>>1)+1, end, L, R);
	
	ST[node] = ST[node<<1] + ST[(node<<1)+1];
}
 
void build(int node, int start, int end){
	if(start == end) ST[node] = arr[start];
	else{
		build(node<<1, start, (start+end)>>1);
		build((node<<1)+1, ((start+end)>>1)+1, end);
		ST[node] = ST[node<<1] + ST[(node<<1)+1];
	}
}
 
void initSegTree(){
	int ht = ceil(log2(N)), i;
	int size = (2*pow(2, ht)) + 5;
	ST = new int[size];
	lazy = new int[size];
	for(i=0;i<size;i++) ST[i] = 0, lazy[i] = 0;
}
 
int main(){
	int i, A, B, op;
	scanf("%d %d",&N, &Q);
	initSegTree();
	for(i=0;i<Q;i++){
		scanf("%d %d %d", &op, &A, &B);
		if(op == 0){
			update(1, 1, N, A, B);
		}else{
			printf("%d\n",queryLazy(1, 1, N, A, B));
		}
	}
return 0;
}
