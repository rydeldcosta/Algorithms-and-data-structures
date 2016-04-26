#include<bits/stdc++.h>

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lf",&x)
#define lli long long int

using namespace std;

int main()
{
	int t;
	s(t);
//	cout<<"sss ";
	while(t--)
	{
		double x,y,t1,t2;
		sl(x),sl(y),sl(t1),sl(t2);
	
		if(t1>y)
			t1=y;
		if(t2>x)
			t2=x;
		double minup,mindown;
		minup = min(x,y-t1);
		mindown = min(y,x-t2);
		//int m = max(x,y);
		double num = x*y-(0.5*minup*minup)- (0.5*mindown*mindown);
		double den = x*y ;
		if(y+t2<x)
			num-=(x-(y+t2))*y;
		if(x+t1<y)
			num-=(y-(x+t1))*x;
		double ans = num/den;
	/*	if(t2==0 && t1==0)
		{
			ans=0.0;
		}*/
		printf("%0.6lf\n",ans);
		
	}
}
