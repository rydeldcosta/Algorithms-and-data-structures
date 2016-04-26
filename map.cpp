#include<iostream>
#include<map>

using namespace std;

int main()
{
	map<int , int> M ;
	int q ,i,j,k;
	for(i=0;i<5;i++)
	{
		cin>>q;
		M[q]++;
	}
	map<int , int>::iterator it = M.begin();
	while(it != M.end())
	{
		printf("%d %d\n",it->first , it->second);
		it++;
	}
	return 0 ;
}
