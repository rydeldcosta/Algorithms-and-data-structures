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
	//primes[2] = 1;
	for(i=2;i<3000;i+=1)
	{
		if(primes[i]==0)
		{
			//primes[i]=1;
			for(j=2*i;j<3000;j+=i)
			{	
				primes[j]++;
			}
		}
	
	}
}

int main()
{
	sieve();
	int t;
	s(t);
	while(t--)
	{
		int n,i,count = 0;
		s(n);
		for(i=29;;i++)
		{
			if(primes[i]>=3)
				count++;
			if(count==n)
				break;
		}
		cout<<i<<endl;
		
	}
//	cout<<primes[3]<<" "<<primes[29]<<primes[652]<<primes[101];
}
