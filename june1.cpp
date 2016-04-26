#include<bits/stdc++.h>

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int



int main()
{
	int t;
	s(t);
	while(t--)
	{
		int n;
		s(n);
		lli ar[n],alloc = 0,ans=0;
		for(int i=0;i<n;i++)
		{
			sl(ar[i]);
			if(ar[i]>alloc)
			{
				ans+=ar[i]-alloc;
				alloc = ar[i];
				
			}
			else if(ar[i]<alloc)
			{
				alloc = ar[i];
			}
			
		}
		printf("%lld\n",ans);
		
	}
}
