#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)//rydeldcosta
#define lli long long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
using namespace std;

int main()
{
	int t;
	s(t);
	while(t--)
	{
		lli n,k;
		sl(n),sl(k);
		lli ar[n],packs=0,extra=0;
		
		for(int i=0;i<n;i++)
		{
			sl(ar[i]);
			if(extra>=ar[i]){
			//	ar[i]=0;
				extra = abs(extra - ar[i]);
				extra--;
				if(extra<0)
					extra=0;
				continue;}
			else
			{
				ar[i]-=extra;
				if(ar[i]!=0){
					if(ar[i]%k==0){
					
						packs+= (ar[i])/k;
						extra=0;}
					else{
						if(ar[i]<k)
						{
							packs++;
						}
						else
							packs+= (ar[i] + k-ar[i]%k)/k;
						extra = k-ar[i]%k-1;
					//extra--;
					}
				}
				else
				{
					extra = 0;
				} 
			}
			
		}
	
		cout<<packs<<endl;
		
	}
}
