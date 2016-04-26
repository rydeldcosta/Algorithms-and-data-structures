#include<bits/stdc++.h>

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define MOD 1000000000

using namespace std;

lli ar[100050],n,maxm,minm,m[10020][10050];



void compute()
{
	int i,j,k,w,x,y,z;
	memset(m,0,sizeof(m));
	maxm=INT_MIN;
	minm=INT_MAX;
	for(i=1;i<=n;i++)
	{
		m[i][i]=ar[i];
		if(maxm<m[i][i])
		{
			maxm = m[i][i];
			w = i,x=i;
		}
		if(minm>m[i][i])
		{
			minm = m[i][i];
			y=i,z=i;
		}
	}
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			
			m[i][j]=m[i][j-1]+ ar[j];
			if(maxm<m[i][j] && (j<y || z<i))
			{
				maxm = m[i][j];
				w = i,x=j;
			}
			if(minm>m[i][j] && (x<i || j<w))
			{
				minm = m[i][j];
				y = i,z=j;
			}
		}
	}
//	cout<<w<<x<<y<<z<<" ";
	printf("%lld\n",abs(maxm-minm));
}
int main()
{
	int t;
	s(t);
	while(t--)
	{
		sl(n);
		for(int i=1;i<n+1;i++)
		{
			sl(ar[i]);
		}
		compute();
	}
}
