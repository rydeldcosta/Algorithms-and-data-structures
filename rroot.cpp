#include<bits/stdc++.h>

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define MOD 1000000000

using namespace std;

int main()
{
	int t;
	s(t);
	while(t--)
	{
		
		lli s;
		sl(s);
		double b,c;
		float ans=0.0;
		b =s/2.0;
		 c = s/2.0;
		 //cout<<b;
		if(b<=4)
		{
			ans = (((b-1)*s + (2.0/3)*b)/(s*b));
		}
		else
		{
			ans = (4.0/3*c*sqrt(c))/(s*c);
		}
		printf("%.6f\n", ans);
	}
}
