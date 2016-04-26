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
		int n,k;
		s(n),s(k);
		int arr[1000][1000];
		M(arr,0);
		int count = 0;
		for(int i=0;i<k;i++)
		{
			int a,b,x,y,a1,b1,x1,y1;
			s(a),s(b);
			x = a1 = x1 = a,y=b1=y1=b;
			if(arr[a][b]==0)
			{
				count++;
				arr[a][b] =1;
			}
			while(b>1 &&a>1)
			{
				
				if(arr[--a][--b]==0)
				{
					arr[a][b] = 1;
					count++;
				}
			}
			while(x<n&&y<n)
			{
				if(arr[++x][++y]==0)
				{
					arr[x][y]=1;
					count++;
				}
			}
			while(y1<n &&x1>1)
			{
				if(arr[--x1][++y1]==0)
				{
					arr[x1][y1] = 1;
					count++;
				}
			}
			while(a1<n &&b1>1)
			{
				if(arr[++a1][--b1]==0)
				{
					arr[a1][b1]=1;
					count++;
				}
			}
			
		}
	/*	for(int i=1;i<=n;i++)
		{
			int j;
			for(j=1;j<=n;j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}*/
		printf("%d\n",n*n-count);
	}
}
