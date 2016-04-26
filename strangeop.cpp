#include<bits/stdc++.h>

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define MOD 1000000000
using namespace std;


int main()
{
	int t,n,k;
	s(t);
	while(t--)
	{
		s(n),s(k);
		lli ar[n],sum=0;
		for(int i=0;i<n;i++)
		{
			s(ar[i]);
			sum+= ar[i];
		}
		//if(sum%2==0)
		//	printf("odd\n");
		//else
		if(k==1)
		{
			if(sum%2==0)
				printf("odd\n");
			else
				printf("even\n");
		}
		else
			printf("even\n");
	}
}
