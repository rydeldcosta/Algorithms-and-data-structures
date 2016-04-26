#include<bits/stdc++.h>

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define MOD 1000000000

using namespace std;

int main()
{
	int t;
	s(t);
	while(t--)
	{
		lli n,a[200000];
		s(n);
		lli k1,k2,k3,ans[100202];
		sl(k1),sl(k2),sl(k3);
		for(int i=1;i<n+1;i++)
		{
			sl(a[i]);
		}
		lli sum=0,k =1;
		ans[0]=0;
		for(int i=1;i<=n;i++)
		{
			sum=a[i];
			ans[k++]=sum;
			for(int j=i+1;j<=n;j++)
			{
				sum+=a[j];
				ans[k++]=sum;
			}
		}
		sort(ans+1,ans+k);
		printf("%lld %lld %lld\n",ans[k-k1],ans[k-k2],ans[k-k3]);
	//	cout<<ans[k-k1]<<" "<<ans[k-k2]<<" "<<ans[k-k3]<<endl;
			
	}
}
