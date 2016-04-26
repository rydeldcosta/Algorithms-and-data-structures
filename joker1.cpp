#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%ld",&x)
#define lli long long int
#define li long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mod 1000000007
using namespace std;

int main()
{
	int t;
	vector<int> v;
	s(t);
	while(t--)
	{
		int n,k;
		s(n);
		v.clear();
		for(int i=0;i<n;i++)
		{
			s(k);
			v.pb(k);
		}
		sort(all(v));
		lli ans=1;
		int j=0;
		for(int i=0;i<n;i++)
		{
			if(v[i]<j)
			{
			ans=0;break;}
			ans*=(v[i]-j+mod)%mod;
			j++;
			if(ans==0)
				break;
		}
		cout<<(lli)ans%mod<<endl;
	}
	cout<<"KILL BATMAN\n";
	cout<<"4";
}
