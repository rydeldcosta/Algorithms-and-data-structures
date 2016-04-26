#include<bits/stdc++.h>
#define ull unsigned long long
#define lli long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define fr first
#define se second
#define gc getchar_unlocked
 
#define MOD 1000000007
using namespace std;

int main()
{
	map<int,int> hsha,hshb,hash;
	while(1)
	{
		hsha.clear();
		hshb.clear();
		hash.clear();
		//int hashA[15000+10005],hashB[15000+10005],hash[15000+10005],i,b;
	//	memset(hashA,0,sizeof hashA);
	//	M(hashB,0);
	//	M(hash,0);
		long long t;
		sl(t);
		if(t==0)
			break;
		lli ar[t+5],sar[t+5];
		sar[0]=0;
		int i;
		F(i,1,t+1)
		{
			sl(ar[i]);
			sar[i] = sar[i-1]+ar[i];
	//		hashA[ar[i]+10005]=i;
	//		hash[ar[i]+10005]++;
			hsha[ar[i]] = i;
			hash[ar[i]]++;
		}
		
		long long n;
		sl(n);
		long long br[n+5],sbr[n+5];
		sbr[0]=0;
		F(i,1,n+1)
		{
			sl(br[i]);
			sbr[i] = sbr[i-1] + br[i];
	//		hashB[br[i]+10005] = i;
	//		hash[br[i]+10005]++;
			hshb[br[i]] = i;
			hash[br[i]]++;
		}
	//	F(i,1,t+1) cout<<sar[i]<<" ";
	//	F(i,1,n+1) cout<<sbr[i]<<" ";
	//	cout<<"sas ";
		long long sum=0;
		int k =0,xprev=0,yprev=0;
		for(int i=1;i<=t;i++)
		{
			//cout<<"sas ";
			if(hash[ar[i]]>=2)
			{
				//cout<<"sas ";
				int x,y;
				x = hsha[ar[i]],y=hshb[ar[i]];
				if(sar[x]-xprev>sbr[y]-yprev)
				{
					sum+=sar[x]-xprev;
					xprev = sar[x];
					yprev = sbr[y];
					//cout<<"sas";
				}
				else
				{
					sum+=sbr[y]-yprev;
					yprev = sbr[y];
					xprev = sar[x];
				//	cout<<sum<<" ";
					
				}
			}
		}
		sum+= max(sar[t]-xprev,sbr[n]-yprev);
		cout<<sum<<endl;
		
		
	}
}
