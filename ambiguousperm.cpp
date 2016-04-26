#include<iostream>
using namespace std;
int main()
{
	
	while(1)
	{
		int t;
		cin>>t;
		if(t==0)
			break;
		int arr[t+1],i,flag = 1;
		arr[0]=0;
		for(i=1;i<t+1;i++)
		{
			cin>>arr[i];
		}
		for(i=1;i<t;i++)
		{
			if(arr[arr[i]]==i)
			{
				continue;
				//printf("ambiguous\n");
				
			}
			else
			{
				//printf("not ambiguous\n");
				flag--;
				break;
			}
		}
		if(flag==1)
		{
			cout<<"ambiguous"<<endl;
		}
		else
		{
			cout<<"not ambiguous"<<endl;
		}
	
	}
		return 0;
}
