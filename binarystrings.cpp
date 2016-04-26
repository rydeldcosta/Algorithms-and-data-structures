#include <string>
#include <cstdio>
#include <vector>
#include <iostream>	
#include<cmath>					
#include <algorithm>
using namespace std;


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int len,k;
		scanf("%d %d", &len, &k);
		char s[10500];
		int cnt[2] = {0};
		for(int i=0;i<len;i++)
		{
			cin>>s[i];
			if(s[i]=='1')
				cnt[1]++;
			else
				cnt[0]++;
		}
	//	cout<<cnt[0]<<cnt[1]<<endl;
		int ones,zeroes;
		ones = ceil((len-k)/2.0);
		zeroes = len-k-ones;
	//	cout<<zeroes<<ones<<endl;
		if(ones>cnt[1])
		{
			zeroes+=ones-cnt[1];
			ones=cnt[1];
		}
		if(zeroes>cnt[0])
		{
			ones+=zeroes-cnt[0];
			zeroes=cnt[0];
		}
	//	cout<<zeroes<<ones<<endl;
		for(int i =0;i<len;i++)
		{
			
			if(s[i]=='1'&&ones)
			{
				s[i]=-1;
				ones--;
			}
			else if(s[i]=='0'&&zeroes)
			{
				s[i]=-1;
				zeroes--;
			}
			if(ones==0 && zeroes==0)
				break;
		}
		for(int i=0;i<len;i++)
		{
			if(s[i]=='0'||s[i]=='1')
				cout<<s[i];
		}
		cout<<endl;
	}
} 
