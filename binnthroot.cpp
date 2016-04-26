#include<bits/stdc++.h>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x);
#define MOD 10000007
using namespace std;

int checkroot(int mid,long long x)
{
	if((int)floor(pow(x,1.0/mid))>1)
		return 1;
	else
		return 0;
}
int root(int mid,long long x)
{
	return floor(pow(x,1.0/mid));
}
int main()
{
	//cout<<floor(pow(55,1.0/2));
	int t;
	s(t);
	while(t--)
	{
		int n,q;
		s(n),s(q);
		int roots[n+1],ar[n+1],sum[n+1],res[q];
		sum[0]=0;
		for(int i=1;i<=n;i++)
		{
			
			s(ar[i]);
			sum[i]=(sum[i-1]+ar[i]+MOD)%MOD;
		}
		int k =0;
		while(q--)
		{
			long long x;
			sl(x);
		/*	for(int i=1;i<=n;i++)
			{
				roots[i]= floor(pow(x,1.0/i));
			}*/
			int lo,hi,ans=0;
			lo = 0;
			hi = 60;
			while(lo<hi)
			{
				int mid =  lo + (hi-lo)/2;
				if(checkroot(mid,x))
					lo = mid+1;
				else 
					hi = mid-1;
			}
			//lo--;
		//	int k = floor(pow(x,1.0/lo));
			//cout<< k <<" "<<lo<<" "<<floor(pow(x,1.0/(lo+1)));
			
			for(int i=1;i<=min(n,lo);i++)
			{
				ans+=(root(i,x)*ar[i])%MOD + MOD;
				ans=ans%MOD;
				
			}
			if(lo>=n)
				cout<<ans<<" ";
			else
				{
					ans+=(sum[n]-sum[lo] +MOD)%MOD;
					cout<<ans<<" ";	
				}
	
			//res[k++]=ans;
		//	cout<<ans<<" ";
		}
		/*for(int i=0;i<q;i++)
			cout<<res[i]<<" ";
		*/
		cout<<endl;
		
	}
}
