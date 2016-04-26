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
//lli hash[1000005][3];
 
 
 //learnt modular arithmetic very important, wrong number of mods can give WA , check if no large value is being stored in a small container(overflow ;})
 
lli modpow(lli base,lli exponent)
	{
	lli result = 1;
	while (exponent > 0)
	{
	if (exponent % 2 == 1)
	result = (result * base) % MOD;
	exponent = exponent >> 1;
	base = (base * base) % MOD;
	}
 
	return result;
	}
 
 
 
 //fermat
	lli inverse(lli num)
	{
	return modpow(num,MOD-2);
	}
 
int main()
{
	int t;
	s(t);
	int i,j;
	
	while(t--)
	{
		int n,x;
		s(n),s(x);
		lli m,arr[n+5];
		sl(m);
		lli tsk=m;
		tsk%=MOD;
		F(i,1,n+1)
		{
			sl(arr[i]);
			arr[i]%=MOD;
			
		}
		if(tsk==0)
	{
		printf("%lld\n",(arr[x])%MOD);
		continue;
	}
		if(x<=2)
		{
			if(x==1)
				printf("%lld\n",arr[1]%MOD);
			else
				printf("%lld\n", (lli)(arr[2]%MOD+((arr[1])%MOD*((m)%MOD)%MOD)%MOD)%MOD);
			
		}
		else{
		
		j=1;
		unsigned lli ans=(arr[x]+ (arr[x-1]%MOD*((m)%MOD)%MOD))%MOD;
		
		unsigned lli lol = m ,tm = m+1;
		for(i=x-2;i>=1;i--)
		{
			unsigned lli fgh = (((tm)%MOD)*inverse(x-i)%MOD)%MOD;
			lol = ((lol%MOD)*(fgh%MOD))%MOD;
			//lol%=MOD;
			ans = (ans%MOD + (arr[i]*lol)%MOD)%MOD;
			
			
			tm++;  
		}
		
			printf("%llu\n",ans%MOD);
	}
	}
}
