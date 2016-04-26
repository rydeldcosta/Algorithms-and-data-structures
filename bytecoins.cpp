#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

map<long long int, long long int> m;
//m[0]=0;
//m[1]=1;m[2]=2;
int coins(long long int x)
{
	//if(x%12 == 0)
	if(x==0)
		return 0;
	if(m.count(x)>0)
		return m[x];				//if atleast a single x is found
	{
		coins(x/2);
		coins(x/3);
		coins(x/4);
		long long int y = m[x/2]+m[x/3]+m[x/4];
		m[x]= max(y,x);
	}
	
}
int main()
{
	//int t = 10;
	long long int x;
	//cin>>x;
	while(scanf("%lld", &x)!=EOF)
	{
		
		
		coins(x);
		cout<<m[x]<<endl;
	}
	
}

