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
	int t;
	s(t);
	while(t--)
	{
		char a[300000],b[300000];
		scanf("%s\n%s",a,b);
		int i=0,current_lane=1,flag = 1,s1=INT_MAX,s2=INT_MAX;
		/*if(a[0]=='.')
			current_lane=1;
		else if(b[0]=='.')
			current_lane = 2;*/
		if(a[0]=='#' && b[0]=='#')
		{
			flag=0;
			//current_lane=0;
		}
	//	cout<<flag;
	if(a[0]=='.')
	{	s1=0;
	
		for(i=0;i<strlen(a)-1 && flag;i++)
		{
			if(a[i+1]=='#' && b[i+1]=='#')
			{
				flag = 0;
				break;
			}
			if(current_lane==1)
			{
				if(a[i+1]=='.')
					continue;
				else
					s1++;
				current_lane=2;
			}
			else if(current_lane==2)
			{
				if(b[i+1]=='.')
					continue;
				else
					s1++;
					current_lane=1;
			}
		}
	}
		current_lane=2;
		if(b[0]=='.')
		{
			s2=0;
		
		for(i=0;i<strlen(a)-1 && flag;i++)
		{
			if(a[i+1]=='#' && b[i+1]=='#')
			{
				flag = 0;
				break;
			}
			if(current_lane==1)
			{
				if(a[i+1]=='.')
					continue;
				else
					s2++;
				current_lane=2;
			}
			else if(current_lane==2)
			{
				if(b[i+1]=='.')
					continue;
				else
					s2++;
					current_lane=1;
			}
		}		
	}
		if(flag)
			printf("Yes\n%d\n",min(s1,s2));
		else
			printf("No\n");
	}
}
