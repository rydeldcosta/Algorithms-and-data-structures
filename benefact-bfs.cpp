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
int visited[100500],ds[100500];
int bfs(vector<pair<int,int> > v[], int x)
{
	M(visited,0);
	M(ds,0);
	queue<pair<int,int> > q;
	q.push(make_pair(x,0));
	int mx=-1,mxj=-1;
	while(!q.empty())
	{
		pii f = q.front();
		q.pop();
		int p  = f.first,dist = f.second;
		visited[p]=1;
		if(mx<dist)
		{
			mx = dist;
			mxj = p;
		}
		for(int i=0;i<v[p].size();i++)
		{
			if(visited[v[p][i].first]!=1)
			{
				int d = v[p][i].second;
				d = d+ dist;
				q.push(make_pair(v[p][i].first,d));
				ds[v[p][i].first] = d;
			}
		}
	}
	return mxj;
}
int main()
{
	int t;
	s(t);
	while(t--)
	{
		int n;
		s(n);
		vector<pair<int,int> > v[n+5];
		for(int i=0;i<n-1;i++)
		{
			int a,b,c;
			s(a),s(b),s(c);
			v[a].pb(make_pair(b,c));
			v[b].pb(make_pair(a,c));
		}
	//	cout<<bfs(v,1)<<endl;
		cout<<ds[bfs(v,bfs(v,1))]<<endl;
	}
}
