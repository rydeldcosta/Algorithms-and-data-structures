#include<iostream>
#include<map>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		map<int, int> mymap;
		int n,d;
		scanf("%d", &n);
		int i,max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d", &d);
			mymap[d]++;
			if(mymap[d]>=max)
				max = mymap[d];
		}
		map<int , int>::iterator it = mymap.begin();
		
			while(it!=mymap.end())
			{
				if(it->second == max)
					break;
				it++;
			}
			printf("%d %d\n", it->first, it->second);
			
		
	}
	return 0;
}
