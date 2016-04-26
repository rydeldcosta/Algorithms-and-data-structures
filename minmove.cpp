#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define MOD 1000000007
#define lli long long int
using namespace std;

string s;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{	cin>>s;
		int len = s.size(),i;
		string mins=s,tmp;
		s.append(s.substr(0,len-1));
		int newn = 2*len-1;
		int j=0;
		for(int i=1;i<len;i++)
		{
			tmp = s.substr(i,newn-i);
			if(tmp<mins)
			{
				mins=tmp;
				j=i;
			}
		}
		cout<<j<<endl;
		
	}
	
}
