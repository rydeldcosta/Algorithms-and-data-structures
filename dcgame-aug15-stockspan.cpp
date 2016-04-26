//stock span problem - geeksfg

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
	int n,m,i,j,k;
	s(n),s(m);
	map<lli,int> M;
	vector<lli> v;
	F(i,0,n)
	{
		lli a;
		sl(a);
		v.pb(a);
		//M[a]++;
	}
	//stock span problem
	stack<int> s;
	int left[n],right[n];
	
	//for left
	s.push(0);
	left[0]=0;
	F(i,1,n)
	{
		
		while(!s.empty()&& v[s.top()]<=v[i])
			s.pop();
		left[i]= (s.empty()? i: i-s.top()-1);
		s.push(i);
	}

	while(!s.empty())
		s.pop();
	//for right
	s.push(n-1);
	right[n-1]=0;
	FD(i,n-2,0)
	{
		
		while(!s.empty()&&v[s.top()]<=v[i] )
			s.pop();
		right[i]= (s.empty()? n-i-1: s.top()-i-1);
		s.push(i);
	}
	
	lli f[n];
	F(i,0,n)
	{
		f[i] = (left[i]+1)*(right[i]+1);
		M[v[i]]+=f[i];
	}	
	
	lli presums[n];
	M(presums,0);
	
	map<lli,int>:: iterator it;
	j=0;
	int finos[n];
	for(it=M.begin();it!=M.end();it++)
	{
	//	cout<<it->second<<" ";
		finos[j]=it->first;
		presums[j] = presums[j-1]+it->second;
		j++;
	}
//	F(i,0,j)
//		cout<<finos[i]<<" ";
char yo[m];
	F(i,0,m)
	{
		char sign,c;
		lli k;
		cin>>sign>>k>>c;
		
		int lo,hi,mid;
		lo=0;hi=M.size();
		while(hi-lo>1)
		{
			mid = (hi+lo)/2;
			if(finos[mid]<=k)
				lo=mid;
			else
				hi=mid;
		}
		lli ans;
		if(sign=='<'){
		if(lo==0)
			ans=0;
		else
			ans=presums[lo-1];
		//	cout<<ans<<endl;
			
		}
		else if(sign=='>')
		{
		
		ans=n*(n+1)/2-presums[lo];
		}
		else{
			ans=M[k];
		}
		if((ans%2==0 && c=='D')||(ans%2==1 && c=='C'))
			yo[i]='C';
		else
			yo[i]='D';
		
		
	}
	printf("%s\n",yo);
	
	
}
