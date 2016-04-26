#include<bits/stdc++.h>

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)


using namespace std;
long long MOD =1000000007;
int C[5500][5500],z[20050];

void compute_z(string s){
   
   int n = s.length();
   memset(z,0,sizeof(z));
 	z[0]=n;
   long long L = 0, R = 0;
   for (long long i = 1; i < n; i++) {
      if (i > R) {
         L = R = i;
         while (R < n && s[R-L] == s[R]) R++;
         z[i] = R-L; R--;
      }
 
      else {
 
         int k = i-L;
         if (z[k] < R-i+1) z[i] = z[k];
         else {
            L = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
         }
      }
   
   }
   
}
int main()
{
	int t;
	s(t);
//	precompute();
	while(t--)
	{
		int n,q;
		
		string s1;
		cin>>s1;
		s(q);
		n=s1.size();
		int cnt[20050],tmp[20050];
		memset(cnt,0,sizeof(cnt));
		for(int i = 0;i<n;i++)
		{
		//	cout<<"sas";
			memset(tmp,0,sizeof(tmp));
			compute_z(s1.substr(i,n-i));		//
			for(int j=0;j<n;j++)		//
			{
				tmp[z[j]]++;
			}
		//	cout<<"sas";
			for(int j=n-1;j>=1;j--)
			{
				tmp[j]+=tmp[j+1];
			}
		
			for(int k=1;k<=n;k++)
			{
				cnt[tmp[k]]++;
			}
		
		
		}
		//for(int i=1;i<n;i++)
		//	cnt[i]=cnt[i]-cnt[i+1];
		long long ans[20050];
		ans[n]=cnt[n];
		for(int i=n-1;i>=1;i--)
		{
			ans[i]=ans[i+1]+cnt[i]*i;
		}
		ans[1]=n*(n+1)/2;
		while(q--)
		{
			long long b,sum=0;
			sl(b);
		/*	for(int i=b;cnt[i]!=0;i++)
			{
				sum+=cnt[i];
			}*/
			if(b>n)printf("0\n");
			else printf("%lld\n",ans[b]);
		}
	}
}
