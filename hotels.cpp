#include<bits/stdc++.h>

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define MOD 1000000000
using namespace std;

int main()
{
//	cout<<"asas";
	lli n;
	lli m,max,sum=0;
//	cout<<"asas";
	s(n),sl(m);
	lli ar[n],prefix[100500];
	for(lli i=0;i<n;i++)
	{
		sl(ar[i]);
	}
	prefix[0] = ar[0];
	max = ar[0];
	lli p=0,q=0;
	if(max==m)
		{
		cout<<max<<endl;
		return 0;
	}
	for(lli i=1;i<n;i++)
	{
		prefix[i] = prefix[i-1] + ar[i];
		
		if(prefix[i]==m)
		{
			max = prefix[i];
			break;
		}
		else if(prefix[i]<m)
		{
			if(max<prefix[i])
				max=prefix[i];
		}
		else
		{
		
		p = q;
		while(prefix[i]-prefix[p]>m)
		{
			p++;
		}
		q = p;
		if(max<prefix[i]-prefix[p])
			max = prefix[i]-prefix[p];
		}
		
		
	}
	printf("%lld",max);
}
