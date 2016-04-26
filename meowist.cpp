#include<bits/stdc++.h>

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define MOD 1000000000

using namespace std;

struct person
{
	char name[50];
	int age;
};


//struct person store[100];

bool cmp(struct person a,struct person b)
{
	if(a.age>b.age)
		return true;
	else if(a.age==b.age)
		return a.name<b.name;
	else
		return false;
}
int main()
{
	
	//int c = 0,x;
	vector<struct person> v;
	struct person tmp;
	//char s[50];
	//int k = 5;
	while(scanf("%s %d",tmp.name, &tmp.age ))
	{
	//	scanf("%s %d",tmp.name, &tmp.age );
		v.push_back(tmp);
		//v.age.push_back(x);
	//	c++;
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].name<<endl;
	}
}
