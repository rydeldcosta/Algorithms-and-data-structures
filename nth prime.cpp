#include<bits/stdc++.h>

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define MOD 1000000000

using namespace std;

int primes[10000];
void sieve()
{
	int i,j;
	
	memset(primes,0,sizeof(primes));
//	primes[0]=primes[1]=1;
	primes[2] = 1;
	for(i=3;i<10000;i+=2)
	{
		if(primes[i]==0)
		{
			primes[i]=1;
			for(j=2*i;j*i<10000;j+=i)
			{	
				primes[j] = 0;
			}
		}
	
	}
}

int main()
{
	sieve();
//	cout<<primes[3]<<" "<<primes[29]<<primes[652]<<primes[101];
}
