#include<stdio.h>
int main()
{
	long long int A , N , K ;
	scanf("%lld%lld%lld" , &A , &N , &K) ;
	while(K--)
	{
		printf("%lld " , A%(N+1)) ;
		A=A/(N+1) ;
	}
} 
