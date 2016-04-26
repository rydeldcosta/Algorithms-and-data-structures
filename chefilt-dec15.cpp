//gauss elimination

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long XORall[100005];
long long XORrev[100005];

char s[25];
int t,n;
int i,j,y;
long long x;
long long final;
long long mult2;
char a[100005][25];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		x=0;
		scanf("%s",s);
		for(i=0;i<10;i++)
		{
			if(s[i]=='b')
			continue;
			else
			x=x|(1<<i);
		}
		cin>>n;
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
			XORall[i]=0;
			for(j=0;j<10;j++)
			{
				if(a[i][j]=='-')
				continue;
				XORall[i]=XORall[i]|(1<<j);
			}
		}
		vector<int>v(XORall,XORall+n);
		sort(v.rbegin(),v.rend());
		for(i=0;i<v.size();i++)
		XORrev[i]=v[i];
		
		{
			long long rankMAT=0;
			long long sig=1;
			while(sig<=XORrev[0])
			{
				sig=sig<<1;
			}
			sig>>=1;
			for(y=0;sig>=1;sig>>=1)
			{
				i=y;
				
				while(i<n && (sig&XORrev[i])==0)
					i++;
				
				if(i>=n)
				continue;
				
				swap(XORrev[i],XORrev[y]);
				for(j=0;j<n;j++)
				{
					if((XORrev[j]&sig)!=0&&j!=y)
					XORrev[j]=XORrev[y]^XORrev[j];
				}
				y=1+y;
			}
			for(i=0;i<n;i++)
			{
				if(XORrev[i]!=0)
				rankMAT++;
			}
			final=0;
			long long found=0;
			for(i=0;i<n;i++)
			{
				long long h=XORrev[i]&x;
				if(h!=0)
				{
					found=found|XORrev[i];
				}
			}
			if(found==x)
			{
				mult2=1;
				for(i=1;i<=n-rankMAT;i++)
				mult2=(mult2*2)%MOD;
				final=mult2;
			}
			printf("%lld\n",final);
		}
		
	}
	return 0;
} 
