#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define li long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
using namespace std;


int main()
{
	int t;
	s(t);
	map<string,int> hash;
	while(t--)
	{
		//memset(hash,0,sizeof(hash));
		hash.clear();
		vector<string> ar(6);
		for(int i=0;i<6;i++)
		{
			cin>>ar[i];
			//char s[20];
			//strcpy(s,ar[i]);
			hash[ar[i]]++;
			if(i%2==1 && ar[i]==ar[i-1])
				hash[ar[i]]--;
		}
		int f =1;
		for(int i=0;i<6;i++)
		{
		//	if(i%2==0)
			{
				if(hash[ar[i]]>=3 )
				{
				f=1;
				break;
				}
				else
					f=0;
			}
		}
	
		if(f)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

}

