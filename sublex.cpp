#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define MOD 1000000007
#define lli long long int
using namespace std;

int gap,sa[100000],pos[100000],tmp[100000],n,lcp[100000];
char s[100000];

bool sufCmp(int i, int j)
{
	if(pos[i]!=pos[j])
	{
		return pos[i]<pos[j];
	}
	i+=gap;
	j+=gap;
	return (i<n&&j<n)?pos[i]<pos[j]:i>j;
}

void buildSA()
{
	n = strlen(s);
	int i;
	for(i=0;i<n;i++)
	{
		sa[i]=i;
		pos[i]=s[i];
	}
	for(gap=1;;gap*=2)
	{
		sort(sa,sa+n,sufCmp);
		tmp[0]=0;
		for(i=0;i<n-1;i++)
		{
			tmp[i+1] = tmp[i] + sufCmp(sa[i],sa[i+1]);
		}
		for(i=0;i<n;i++)
		{
			pos[sa[i]]=tmp[i];
		}
		if(tmp[n-1]==n-1)
			break;
	}
	
}
void buildLCP()
{
	int i,j,k;
	for(i=0,k=0;i<n;i++)
	{
		if(pos[i]!=n-1)
		{
			for(j=sa[pos[i]+1];s[i+k]==s[j+k];)		//compares neighboring pos
			{
				k++;
			}
			lcp[pos[i]] = k;			//reused k
			if(k>0)
				k--;
			
		}
	}
}
int main()
{
	scanf("%s",s);
	buildSA();
	buildLCP();
	int t;
	scanf("%d",&t);
	//REP(i,n) cout<<sa[i];
	//co//ut<<endl;
	//REP(i,n) cout<<lcp[i];
	while(t--)
	{
		long long k;
		scanf("%lld", &k);
		int kt = k;
		int i,j=0;
		for(i=0;i<n;)
		{
			if(i==0)
			{
				if(kt<=n-sa[i])
				{
					break; //
				}
				else
				{
					kt-=(n-sa[i]);
					i++;
				//	cout<<kt<<endl;
					
				}
			}
			else
			{
				if(kt<=n-sa[i]-lcp[i-1])
				{
					break; //
				}
				else
				{
					kt-=(n-sa[i]-lcp[i-1]);
					i++;
					
				}
				
			}
		}
		if(i==0)
		{
			for(int d=sa[i];d<sa[i]+kt;d++)	//
			{
				cout<<s[d];
			}
			cout<<endl;
		}
		else
		{
		//	cout<<sa[i]<<" "<<kt+sa[i];
			for(int d=sa[i];d<lcp[i-1]+kt+sa[i];d++)
			{
				cout<<s[d];
			}
			cout<<endl;
		}
		
	}
	//REP(i,n) cout<<sa[i];
	//cout<<endl;
	//REP(i,n) cout<<lcp[i];
}
