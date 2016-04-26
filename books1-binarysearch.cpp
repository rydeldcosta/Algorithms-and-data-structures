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

lli arr[600];
int slash[600],sls[600];
int n,rem;
int  solve(lli m,int w)
{
	int count=0,i,j=0,sum=0;
	M(slash,0);
	F(i,0,n)
	{
		if(sum+arr[i]<=m)
		{
			sum+=arr[i];
		}
		else 
		{
			if(w==0)
				return 0;
		//	cout<<i-1<<" ";
			slash[j++]= i-1;
			w--;
			sum=arr[i];
		}
		if(w>j)
			rem = w-j;
		
	}
	F(i,0,j)
		sls[i] = slash[i];
	//if(sum>m)
	//	return 0;
	return 1;
	
}
void final(lli m,int w)
{
	int i,j=0;
	lli sum=0;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
		if(rem>0)
		{
			cout<<"/ ";
			rem--;
		}
		if(sls[j]==i)
		{
			cout<<"/ ";
			j++;
		}
		
	}
	cout<<endl;
}
int main()
{
	int t;
	s(t);
	while(t--)
	{
		int w;
		s(n),s(w);
		
		int i;
		lli mx=INT_MIN,lo,hi=0;
		F(i,0,n)
		{
			sl(arr[i]);
			hi+=arr[i];
			mx = max(mx,arr[i]);
		}
		lo = mx;
		lli mid;
		while(lo<hi)
		{
			mid = lo+(hi-lo)/2;
		//	cout<<mid<<" ";
			if(solve(mid,w-1))
				hi = mid;
			else
				lo = mid+1;
		}
		final(lo,w-1);
	//	cout<<lo<<endl;
	}
}
