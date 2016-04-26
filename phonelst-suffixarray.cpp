#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define MOD 1000000007
#define lli long long int
using namespace std;

int gap,sa[100],pos[100],tmp[100],n,lcp[100];


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
void buildLCP(char s[])
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
	int t;
	cin>>t;
	while(t--)
	{
	int cases;
	cin>>cases;
	char ar[cases][15];
	for(int i=0;i<cases;i++)
	{
		scanf("%s",ar[i]);
	} 
	int j,k,flag=1;
	for(j=0;j<cases-1;j++)
	{
		for(k=j+1;k<cases;k++)
		{
			char s[10000];
			int x,y,i;
			x = strlen(ar[j]);
			y = strlen(ar[k]);
			strcpy(s,ar[j]);
			s[x] = '$'; 
			for(int i=x+1;ar[k][i-x-1]!='\0';i++)
			{
				s[i] = ar[k][i-x-1];
			}
			memset(sa,0,sizeof(sa));
			memset(lcp,0,sizeof(lcp));
			buildSA(s);
			buildLCP(s);
//			cout<<s<<endl;
			for(i=0;;i++)
			{
				if(sa[i]==0)
					break;
			}
			if(i<strlen(s)&&lcp[i]==x)
			{
//				cout<<"sassas";
				flag=0;
				break;
			}
			
		}
		if(flag==0)
				break;
	}
	
	//cout<<i<<endl;
	//REP(i,n) cout<<sa[i];
	//cout<<endl;
	//REP(i,n) cout<<lcp[i];
	if(flag==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	}
	
}
