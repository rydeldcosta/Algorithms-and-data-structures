#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%ld",&x)
#define li long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
using namespace std;


int main()
{
	int t;
	s(t);
	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()>s2.size()) {
		cout<<"0\n";continue;}
		int n = s2.size()/s1.size() + 1;
		
		//bin srch
		int l = 0,h = n,mid,flag=1,j=0,ans=0;
		while(l<=h)
		{
			mid = l + (h-l)/2;
			if(mid*s1.size()>s2.size())
				l=mid+1;
			else
			{
				j=0;
				int tmp = mid;
				for(int i=0;i<s1.size();i++)
				{
					//j=i+1;
					while(tmp && j<=s2.size())
					{
						if(s1[i]==s2[j])
							tmp--;
						j++;
					}
					if(j>s2.size()){
						flag = 0;break;
					}
					if(tmp==0)flag=1;
					tmp=mid;
				}
				if(flag==1)
				{
					ans = mid;
					l = mid+1;
				}
				else
					h=mid-1;
			}
		}
	
		cout<<ans<<endl;
		
	}
}
