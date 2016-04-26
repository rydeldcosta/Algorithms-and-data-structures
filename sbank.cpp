#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%ld",&x)
#define li long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
using namespace std;

struct acc
{
	string str;
	string num;
//	int count=1;
};
bool cmp(struct acc a, struct acc b)
{
	if(a.str==b.str)
	{
	//	b.count += (a.num<b.num?1:0);
		return a.num<b.num;
	}
	
	else
	{
	//	a.str<b.str?b.count++:a.count++;
		return a.str<b.str;
	}
}
int main()
{
	int t;
	s(t);
	while(t--)
	{
		vector<struct acc> vec;
		map<string,int> M;
		int n;
		s(n);
		int count = 1;
		for(int i=0;i<n;i++)
		{
			string s,s1;
			struct acc tmp;
			for(int j=0;j<5;j++)
			{
				cin>>s1;
				s.append(s1);
				s.append(" ");
			}
			tmp.str = s;
			
				//count--;
			pair<string,int> p1;
			p1.first = s,p1.second=count;
			M.insert(p1);
		//	M[s]=count;
			if(M[s]<1)
				count++;
			
			cin>>s1;
			tmp.num = s1;
			vec.pb(tmp);
		}
		sort(all(vec),cmp);
		for(int i=0;i<n;i++) {
			//for(int j=0;j<vec[i].str.size();j++)
			{
				cout<<vec[i].str<<vec[i].num<<" ";
				cout<<M[vec[i].str];
			//	if(j==1||j==9||j==13||j==17||j==21)
					cout<<" ";
			}
			cout<<endl;}
	}
}
