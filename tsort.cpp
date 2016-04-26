#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long int n;
	//scanf("%d", &n);
	cin>>n;
	int arr[100001]= {0};
	int b;
	
		while(n--)
		{
			cin>>b;
			arr[b]++;
		}
		for(int i =0;i<n;i++)
		{
			if(arr[i]!=0){
			
			while(arr[i]>0)
			{
				//cout<<i<<endl;
				printf("%d\n", i);
				arr[i]--;
			}
		}
		}
	//return 0;	
	
}
