#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<stdlib.h>
#define MOD 1000000009

using namespace std;
long long int arr[1001][1001];

long int binarySearch(long long int arr[], long long int key)
{
	long int low =2, high=1000,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		
		if(key<arr[mid])
			high = mid-1;
			
		else if(key>arr[mid])
			low = mid+1;
		else
			return mid;
	}
	return -1;
}


int main()
{
	int t;
	long i,j;
	char num[1002];
	scanf("%d",&t);
	
	for(i=1; i<=1000; i++)
	{
		for(j=1; j<=1000; j++)
		{
			if(i==1 || j==1)
				arr[i][j]=1;
			
			else
				arr[i][j]=(arr[i-1][j]%MOD+arr[i][j-1]%MOD)%MOD;
			
					
		}
	}
	long long int temp;
	
	while(t--)
	{
		scanf("%s",num);
		
		temp = 0;
		
		for(i=0; i<strlen(num);i++)
		{
			temp = temp*10 + num[i]-'0';
			if(temp>=MOD)
				temp = temp%MOD;
		}	


		if(temp==1)
		{
			printf("1999\n");
			for(i=1; i<=1000; i++)
			{
				if(i==1)
				{
					for(j=1; j<=1000; j++)
						printf("%ld %ld\n",i,j);
				}
				else
					printf("%ld 1\n",i);
			}
			continue;
		}
		
		
	bool found = false;

	for(i=2; i<=1000; i++)
	{
		j = binarySearch(arr[i],temp);
		
		if(j!=-1)
		{
			found = true;
			printf("%ld %ld\n",i,j);
		}
	}
	
	if(!found)
		printf("The Grid is Too Big!\n");
	
	}
	
	
	
	
}
