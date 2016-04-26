#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
using namespace std;

int main()
{
	int t;
	s(t);
	long long ar[t];
	long long hash[]={1,4,4,4*4,4*4,4*4*4,4*4*4,4*4*4*4,4*4*4*4,4*4*4*4*4,4*4*4*4*4};

	for(int i=0;i<t;i++)
	{
		sl(ar[i]);
}
	for(int i=0;i<t;i++)
	{
	
		lli c = 0,c2=0;
		lli t = ar[i];
		while(t>0)
		{
		
			if(t%10==0)
			{
				c2++;
				c++;
				t/=10;
				continue;
			}
			else if(t%5==0)
			{
				c++;
				
				t/=5;
			}
			else break;
			
		}
		int x = abs(c2-c);
		if(x==0)
			cout<<(lli)ar[i]<<endl;
		else
			cout<<(lli)ar[i]*(lli)hash[x]<<endl;
	}
}
