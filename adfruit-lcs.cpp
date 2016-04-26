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

int lcs[150][150];
char a[150],b[150];

int lcsprint(int x,int y)
{
	if(x==0)
		{
		lcs[0][y]=y;
		return y;}
	if(y==0){
	
		lcs[x][0]=x;
		return x;
	}
	if(lcs[x][y]!=0)
		return lcs[x][y];
	if(a[x-1]==b[y-1])
	{
		lcs[x][y] = 1 + lcsprint(x-1,y-1);
		return lcs[x][y];
	}
	else{
	
		lcs[x][y] = 1 + min(lcsprint(x-1,y),lcsprint(x,y-1));
		return lcs[x][y];}
	
}
void backtrack(int l,int x, int y)
{

	int idx = l,i,j;
	char str[idx+1];
	str[idx]='\0';
	idx--;
	i = x;j=y;
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			str[idx] = a[i-1];
			i--;
			j--;
			idx--;	
		}
		else if(lcs[i-1][j]<lcs[i][j-1])
		{
			
			str[idx--] = a[i-1];
			i--;
		}
		else
		{
			str[idx--] = b[j-1];
			j--;
		}
	}
	if(j!=0)
	{
		while(j>=0)
		{
			str[idx--] = b[j-1];
			j--;
		}
	}
	else if(i!=0)
	{
		while(i>=0)
		{
			str[idx--]= a[i-1];
			i--;
		}
	}
	cout<<str<<endl;
}


int main()
{
	
	while(scanf("%s",a)!=EOF)
	{
		scanf("%s",b);
		
		M(lcs,0);
		int ans = lcsprint(strlen(a),strlen(b));
		backtrack(ans,strlen(a),strlen(b));
		int i,j;
	
	}
}
