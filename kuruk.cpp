#include <string>
#include <cstdio>
#include <vector>
#include <iostream>	
#include<cmath>					
#include <algorithm>
#define s(x) scanf("%d",&x)
using namespace std;


int main()
{
	int t;
	s(t);
	while(t--)
	{
		int n;
		s(n);
		int ar[n],hash[10500]={0};
		for(int i=0;i<n;i++)
		{
			s(ar[i]);
			hash[min(ar[i],n-1-ar[i])]++;
		}
		int flag=1;
		for(int i=0;i<n/2;i++)
		{
			if(hash[i]!=2)
			{
				cout<<"NO\n";
				flag=0;
				break;
		}
		}
		if(flag)
			cout<<"YES\n";
	}
}
