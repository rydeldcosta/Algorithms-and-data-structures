#include<bits/stdc++.h>				//fermats little thrm

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define MOD 1000000000

using namespace std;


 
long long mulmod(long long a,long long b,long long c){
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
}
 
/*bool fermat(lli p)
{
	if(p==1)
		return false;
	int iterations = 1000;
	for(int i=0;i<iterations;i++)
	{
		//generate randome int
		lli a = rand()%(p-1) +1;
		//check a^p-1==1
		if(fastpow(a,p-1,p)!=1)
			return false;
		
	}
	return true;
}*/
bool Miller(long long p){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    int iteration = 20;
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long modu=mod(a,temp,p);
        while(temp!=p-1 && modu!=1 && modu!=p-1){
            modu=mulmod(modu,modu,p);
            temp *= 2;
        }
        if(modu!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

int main()
{
	int t;
	s(t);
	while(t--)
	{
		lli p;
		sl(p);
		if(Miller(p))
		{
			cout<<"YES\n";
		}
		else
			cout<<"NO\n";
	}
	
}
