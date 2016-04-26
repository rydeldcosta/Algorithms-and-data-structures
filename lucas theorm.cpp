#include <bits/stdc++.h>
    #define lld long long int
    #define MOD 1000003
    using namespace std;
    lld fact[10000100],ifact[10000100];
   
    
    lld C(lld n,lld k)
    {
    	lld result=1;
    	while(n>0)
    	{
    		lld N=n%MOD;
    		lld K=k%MOD;
    		
    		if(K>N)
    		return 0;
   			
    		result*=(((fact[N]*ifact[K])%MOD)*ifact[N-K])%MOD;
    		result%=MOD;	
    	//	cout<<fact[N]<<" "<<K<<" "<<N-K<<" "<<result<<endl;
    		n/=MOD;
    		k/=MOD;
    	}
    	return result;
    }
    
 
    lld modpow(lld base,lld exponent)
	{
	lld result = 1;
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
	lld inverse(lld num)
	{
	return modpow(num,MOD-2);
	}
 
    int main()
    {
    	lld i,j;
    	fact[0]=1;
    	ifact[0]=1;
    	for(i=1;i<MOD;i++)
    	{
    		fact[i]=(i*fact[i-1])%MOD;	
    		ifact[i]=(inverse(i)*ifact[i-1])%MOD;
    	}
    	int t;
    	cin>>t;
    	while(t--)
    	{
    		lld n,l,r;
    		cin>>n>>l>>r;
    		
    		lld f1=n+r-l+1;
    		lld f2=r-l+1;
    		
    		lld p=C(f1,f2);
    		if(p)
    		cout<<p-1<<endl;
    		else
    		cout<<1000002<<endl;
    	}
    } 
