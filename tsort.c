//#include<iostream>
#include<stdio.h>
//#include<cstdio>
//using namespace std;
int main()
{
	long long int n;
	scanf("%d", &n);
	//cin>>n;
	int arr[100001]= {0};
	int b,i;
	
		while(n--)
		{
			//cin>>b;
			scanf("%d", &b);
			arr[b]++;
		}
		for( i =0;i<n;i++)
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
	return 0;	
	
}
