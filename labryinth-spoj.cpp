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
char arr[1024][1024];
int visited[1024][1002];
int ds[1002][1002];
int c,r;
int isafe(int i,int j)
{
	if(i>=0&&i<r && j>=0 && j<c && visited[i][j]!=1) return 1;
	return 0;
}
pii bfs(int i, int j)
{
	M(ds,0);
	queue<pair<int,int> >q;
	ds[i][j]=0;
	int x,y;
	int mxi,mxj,mx=-1;
	q.push(make_pair(i,j));
	while(!q.empty())
	{
		pii g = q.front();
		q.pop();
		 x = g.first,y=g.second;
		visited[x][y] = 1;
		if(isafe(x-1,y) && arr[x-1][y]=='.')
		{
			
			q.push(make_pair(x-1,y));
			ds[x-1][y] = 1+ds[x][y];
			
		}
		if(isafe(x+1,y) && arr[x+1][y]=='.')
		{
			q.push(make_pair(x+1,y));
			ds[x+1][y] = 1+ds[x][y];
		}
		if(isafe(x,y-1) && arr[x][y-1]=='.')
		{
			q.push(make_pair(x,y-1));
			ds[x][y-1] = 1+ds[x][y];
		}
		if(isafe(x,y+1) && arr[x][y+1]=='.')
		{
			q.push(make_pair(x,y+1));
			ds[x][y+1] = 1+ds[x][y];
		}
		
		if(ds[x][y]>mx)
		{
			mx = ds[x][y];
			mxi = x,mxj=y;
		}
	}
	return make_pair(mxi,mxj);
	
}

int main()
{
	int t;
	s(t);
	while(t--)
	{
		
		s(c),s(r);
		int i,j;
		int xi,xj;
		F(i,0,r)
		{
			F(j,0,c)
			{
				
				cin>>arr[i][j];
				if(arr[i][j]=='.')
				{
					xi = i,xj  = j;
				}
			}
		}
		M(visited,0);
	//	cout<<xi<<" "<<xj<<endl;
		pii ans = bfs(xi,xj);
	//	cout<<ans.fr<<" "<<ans.se<<endl;
		M(visited,0);
		pii ans2 = bfs(ans.fr,ans.se);
	//	cout<<ans2.fr<<" "<<ans2.se<<endl;
		cout<<"Maximum rope length is "<<ds[ans2.fr][ans2.se]<<"."<<endl;
		
		
	}
}
