#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%ld",&x)
#define li long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
using namespace std;
vector<long> a,b,c,d,ab,cd;
int binsearch(long x)
{
	int l=0,h = cd.size(),mid,tmp,size2=0,i,j;
	while(l<=h)
	{
		mid = l+(h-l)/2;
		if(cd[mid]==x)
		{
			tmp = mid;
			while(cd[mid]==x&& mid<cd.size()){
				
			 size2++,mid++;}
			tmp--;
			while(cd[tmp]==x &&tmp>=0) {
			tmp--,size2++;}
			return size2;
		}
		else if(cd[mid]<x)
			l = mid+1;
		else 
			h = mid-1;
	}
	return 0;
}
int main()
{
	int n;
	s(n);

	long x,y,z,w;
//	li hash[5000];
//	memset(hash,0,sizeof(hash));
//	a.clear(),b.clear(),c.clear(),d.clear(),ab.clear(),cd.clear();
	for(int i=0;i<n;i++) 
	{
		sl(x),sl(y),sl(z),sl(w);
		a.pb(x),b.pb(y),c.pb(z),d.pb(w);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ab.pb(a[i]+b[j]);
			//hash[abs(a[i]+b[i])]++;
		}
	}
	sort(all(ab));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cd.pb(c[i]+d[j]);
			//hash[abs(c[i]+d[j])]++;
		}
	}
	sort(all(cd));
	li count = 0;
	for(int i =0;i<ab.size();)
	{
		//cout<<ab[i++]<<endl;
		int tmp= ab[i];
		int size1=0,size2=0;
		while(ab[i]==tmp && i<ab.size()) {
			size1++,i++;
		}
		
		size2 = binsearch(-tmp);
	//	cout<<size1<<" "<<size2<<endl;
		count+= size1*size2;
	}

	cout<<count<<endl;
		
}
