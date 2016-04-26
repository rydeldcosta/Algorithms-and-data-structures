#include<iostream>
#include<algorithm>


#define S(x) scanf("%d",&x)
#define SLL(x) scanf("%lld",&x)
#define P(x) printf("%d",x)
#define PLL(x) printf("%lld",x)
#define lli long long int 
using namespace std;

lli gcd(lli a,lli b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
void calc(lli a, lli b)
{
	if(b==1)
		{
			printf("Yes\n");
			return;
		}
	lli d;
	d = gcd(a,b);
	if(d==1)
	{
		printf("No\n");
		return;
	}
	else
		return calc(a,b/d);
}
int main()
{
	int t;
	S(t);
	while(t--)
	{
		long long a,b;
		SLL(a);
		SLL(b);
		calc(a,b);
	}
}
