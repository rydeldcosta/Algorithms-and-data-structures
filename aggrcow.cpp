#include<bits/stdc++.h>

using namespace std;

long long ar[1000520];
int check(long long mid, long long n, long long cows)
{
	long long i,cowsplaced = 1,x,lastplaced = 0;
	for(i=1;i<n;i++)
	{
		if(ar[i]-ar[lastplaced]>=mid)
			{
				cowsplaced++;
				lastplaced = i;
			}
			if(cowsplaced== cows)
				return 1;
	}
	return 0;
}
void binarysearch(long long n,long long cows)
{
	long long lo,hi,mid;
	lo = 0;
	hi = ar[n-1];
	while(lo<hi)
	{
		mid = lo + (hi-lo)/2;
		if(check(mid,n,cows))
			lo = mid+1;
		else 
			hi = mid;
			
	}
	cout<<lo-1<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int stalls, cows,x;
		cin>>stalls>>cows;
		for(int i=0;i<stalls;i++)
		{
			scanf("%lld",&ar[i]);
			
		}
		sort(ar,ar+stalls);
		binarysearch(stalls,cows);
	}
}
