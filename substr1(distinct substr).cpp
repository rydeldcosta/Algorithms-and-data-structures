#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define MOD 1000000007
#define lli long long int
using namespace std;

int gap,sa[100000],pos[100000],tmp[100000],n,lcp[100000],sum;


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

void buildSA(char s[])
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
int buildLCP(char s[])
{
	memset(lcp,0,sizeof(lcp));
	int i,j,k;
	sum=0;
	for(i=0,k=0;i<n;i++)
	{
		if(pos[i]!=n-1)
		{
			for(j=sa[pos[i]+1];s[i+k]==s[j+k];)		//compares neighboring pos
			{
				k++;
			}
			lcp[pos[i]] = k;
			sum+=k;			//reused k
			if(k>0)
				k--;
			
		}
	}
	return sum;
}
int main()
{
	int t;
	char s[100000];
	cin>>t;
	while(t--)
	{
		memset(sa,0,sizeof(sa));
		memset(tmp,0,sizeof(tmp));
		memset(pos,0,sizeof(pos));
		scanf("%s",s);
		int l=strlen(s);
		buildSA(s);
		int m=buildLCP(s);
	//	REP(i,n) cout<<sa[i];
		cout<<l*(l+1)/2-m<<endl;
	//	REP(i,n) cout<<lcp[i];
		
	}
	
}

