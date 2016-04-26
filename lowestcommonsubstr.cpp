#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define MOD 1000000007
#define lli long long int
using namespace std;

int gap,sa[600000],pos[600000],tmp[600000],n,lcp[600000];
char s[600000];

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
bool cmp(int x, int y)
{
	
}
int main()
{
	char a[300000],b[300000];
	scanf("%s %s",a,b);
	strcpy(s,a);
	int x,y;
	x=strlen(a),y=strlen(b);
	s[x]='$';
	for(int i=x+1;b[i-x-1]!='\0';i++)
			{
				s[i] = b[i-x-1];
			}
	buildSA();
//	cout<<s<<endl;
	buildLCP();
	//sort(lcp,lcp+x+y+1,cmp);
	int max = INT_MIN;
	for(int i=0;i<x+y+1;i++)
	{
		if(lcp[i]>max && (sa[i]>=x+1 || sa[i+1]>=x+1))		// checks if it doesnt belong to same string :)
			max = lcp[i];
	//	if(i==min(x,y))
	//		break;
	}
//	REP(i,n) cout<<sa[i];
	cout<<max<<endl;
	REP(i,n) cout<<lcp[i];
}
