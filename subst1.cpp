#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<new>
#include<set>
#define pb(x) push_back(x)
#define loop(i, a, b) for (int i=a; i<b; i++)
#define rloop(i, a, b) for (int i=a; i>=b; i--)
#define MOD 1000000007
typedef long long int lli;
using namespace std;

int z[50005], cnt[50005], temp[50005];
 
void z_algo(string s)
{
	int n=s.size();
	int L, R, k;
	z[0]=s.size();
	L=R=0;
	loop(i, 1, n)
	{
		if (i>R)
		{
			L=R=i;
			while (R<n && s[R-L]==s[R]) R++;
			z[i]=R-L;
			R--;
		}
		else
		{
			k=i-L;
			if (z[k]<R-i+1) z[i]=z[k];
			else
			{
				L=i;
				while (R<n && s[R-L]==s[R]) R++;
				z[i]=R-L;
				R--;
			}
		}	
	}	
 
}
 
 
 
int main()
{
//	solvenCr();
	int t, q, k, n;
	string s;
	cin>>t;
	while (t--)
	{
		
		
	//	cin>>n>>q;
		cin >> s;
		n=s.size();
		loop(i, 1, n+1)
		{
			temp[i]=0;
			cnt[i]=0;
			z[i]=0;
			//ans[i]=0;
		}
		loop(i, 0, n)
		{
			loop(j, 1, n+1)
			{
				temp[j]=0;
				z[j]=0;
			}
			z_algo(s.substr(i, n-i));
			
			loop(j, 0, n)
			{
				temp[z[j]]++;
			}
			rloop(j, n-1, 1)
			{
				temp[j]+=temp[j+1];
			}
 
			loop(j, 1, n+1)
			{
				cnt[temp[j]]++;
			}
			
		}
		cout<<cnt[1]<<endl;
 

		
		
	}
	return 0;
}
