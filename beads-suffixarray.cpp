#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define MOD 1000000007
#define lli long long int
using namespace std;

int gap,sa[10500],pos[10500],tmp[10500],n;
string s;

bool sufCmp( int i , int j )
{
  int oi = i;
  int oj = j;
  if( pos[i] != pos[j] )
    return pos[i] < pos[j];
  i += gap;
  j += gap;
  if( i >= oi + n || j >= oj + n )				//the adjustment is made here
    return i <= j;
  else return pos[i%n] < pos[j%n];
}

void buildSA()
{
	n = s.size();
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

int main()
{
	int t;
	scanf("%d", &t);
	
	while(t--)
	{	cin>>s;
		int len = s.size(),i;
		buildSA();
	

		int min=INT_MAX;
		 i=0;
	/*	while(sa[i]>len)
		{
			i++;
		}*/
		printf("%d\n",sa[i]+1);

		
	}
	
}
