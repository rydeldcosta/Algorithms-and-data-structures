#include<bits/stdc++.h>

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define MOD 1000000000

using namespace std;

int fastpow(int a, lli b,int c)
{
	int i,j,x=1,y=a;
	while(b)
	{
		if(b%2==1)
		{
			x=(x*y)%c;
		}
		y = (y*y)%c;
		b /=2;
	}
	return x%c;
}
//or   handles ovwrflow :)
/*long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
long long mod(long long a,long long b,long long c){
    long long x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=mulmod(x,y,c);
        }
        y = mulmod(y,y,c); 
        b /= 2;
    }
    return x%c;
}*/

int main()
{
	int t;
	s(t);
	while(t--)
	{
		int a;
		lli b;
		s(a),sl(b);
		cout<<fastpow(a,b,10)<<endl;
	}
	
}
