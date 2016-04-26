#include<iostream>
#include<string.h>
#include<map>

using namespace std;

map<int,int> M;

int main()
{
	int n,k,count = 0;
	scanf("%d %d", &n, &k);
	while(k--)
	{
		char s[10];
		int a;
		scanf("%s", s);
		if(!strcmp(s,"CLOSEALL"))
		{
		
			count = 0;
			for(int i=1;i<n+1;i++)
				M[i]=0;
			cout<<count<<endl;
			continue;
		}
		else
		{
			scanf("%d", &a);
			if(M[a]==0)
			{
				count++;
				M[a]++;
				//cout<<M[a]<<"a";
			}
			else
			{
				count--;
				M[a]--;
				//cout<<M[a]<<"B";
			}
			cout<<count<<endl;
		}
		
	}
}
