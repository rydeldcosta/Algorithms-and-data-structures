#include<bits/stdc++.h>

using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<string> vec;
		int n;
		cin>>n;
		vec.resize(50000);
		int i;
		char s[50];
		for(i=0;i<n;i++)
		{
			cin>>s;
			vec[i]=s;
		}
		//cout<<vec[2];
		sort(vec.begin(),vec.end());
		//cout<<vec[1][0];
		int flag=1;
		for(i=0;i<n-1;i++)
		{
			flag=1;
			if(vec[i].size()>vec[i+1].size())
				continue;
			for(int j=0;vec[i][j]!='\0';j++)
			{
				if(vec[i][j]!=vec[i+1][j])
				{
					flag = 0;
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==0)
		{
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
		
	}
}
