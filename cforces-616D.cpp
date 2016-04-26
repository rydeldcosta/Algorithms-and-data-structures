#include<bits/stdc++.h>
#define ull unsigned long long
#define lli long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define fr first
#define se second
#define gc getchar_unlocked
 
#define MOD 1000000007
using namespace std;

int main()
{
	int n,k;
	s(n),s(k);
	set<int> S;
	int i,j;
	int arr[n];
	for(i=0;i<n;i++)
	{
		s(arr[i]);
	}
	int l=0,r=1,left,right;
	S.insert(arr[0]);
	int ans = INT_MIN;
	while(r<n)
	{
		S.insert(arr[r]);
		if(S.size()>k)
		{
			S.erase(arr[l]);
			l++;
			
			//continue;
		}
		
		int m = S.size();
		if(r-l+1>ans)
		{
			left = l;right = r;ans = r-l+1;
		}
		r++;
		
	}
	cout<<left+1<<" "<<right+1<<endl;
	//printf("%d %d\n",left+1,right+1);
}
