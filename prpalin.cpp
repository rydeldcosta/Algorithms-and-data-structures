
#include<iostream>
#include<cmath>
using namespace std;
long long int nextPrime(long long int x){
    int i,k;
    if(x%2==0)
    {
    	return nextPrime(++x);
    }
    for(i=3;(i<=sqrt(x));i=i+2)
    	if(x%i==0){ 
    		k=x+2;
            return nextPrime(k);
        }
        else if(x==i) {
            
            return x;
        }
        else {
        	/*if(x%2==0)
            	return nextPrime(++x);*/
            
            	k=x+2;
            	return nextPrime(k);
        }
}

int palin(long long int x)
{
	int tmp = x;
	int sum = 0;
	while(x>0)
	{
		int a = x%10;
		sum = sum*10 + a;
		x=x/10;
		
	}
	if(sum==tmp)
	{
		return 1;
	}
	else 
		return 0;
}
int main()
{
	long long int x;
	cin>>x;
	while(1){
	long long int z=nextPrime(x+1);
	long long int b = palin(z);
	if(b==1){
	
		cout<<z<<endl;
		break;
	}
	x+=2;
	}
	
	

return 0;
}
