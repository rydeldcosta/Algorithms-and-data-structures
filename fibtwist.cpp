#include<stdio.h>
long long int MOD;
int i, j, k;
long long fib_fn(int n)
{
	long long int fib[2][2]={{1,1},{1,0}}, ans[2][2]={{1,0},{0,1}}, temp[2][2]={{0,0},{0,0}};
	while(n)
	{
		if(n%2==1)
		{
			for(i=0;i<2;i++)
				for(j=0;j<2;j++)
					temp[i][j]=0;
			for(i=0;i<2;i++) 
				for(j=0;j<2;j++)
					for(k=0;k<2;k++)
						temp[i][j]=(temp[i][j]+ans[i][k]*fib[k][j])%MOD;
			for(i=0;i<2;i++) 
				for(j=0;j<2;j++) 
					ans[i][j]=temp[i][j];
		}
		for(i=0;i<2;i++)
				for(j=0;j<2;j++)
					temp[i][j]=0;
		for(i=0;i<2;i++) 
			for(j=0;j<2;j++) 
				for(k=0;k<2;k++)
					temp[i][j]=(temp[i][j]+fib[i][k]*fib[k][j])%MOD;
		for(i=0;i<2;i++)
			for(j=0;j<2;j++) 
				fib[i][j]=temp[i][j];
		n/=2;

	}
	return (ans[0][1])%MOD;
}

int main()
{
	int t;
	long long m,n;
	for(scanf("%d",&t);t>0;t--)
	{
		scanf("%lld%lld",&n,&MOD);
		long long res = (2*(fib_fn(n+2)-1)-n)%MOD;
		if(res<0)res+=MOD;
		printf("%lld\n", res);
	}
	return 0;
}
