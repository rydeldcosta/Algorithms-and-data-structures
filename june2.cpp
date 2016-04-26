#include<bits/stdc++.h>

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
using namespace std;

struct vertex
{
	lli x,y;
}v[100025];
struct ply
{
	double maxd;
	int num,po;
}poly[102350];

bool vcompare(struct ply lhs, struct ply rhs){
	return lhs.maxd<rhs.maxd;
}																		//importance of comparator function
bool pocompare(struct ply lhs, struct ply rhs){
	return lhs.po<rhs.po;
}
double dist(struct vertex h)
{
	return sqrt(h.x*h.x + h.y*h.y);
}
int main()
{
	int t;
	s(t);
	while(t--)
	{
		int n;
		s(n);
		int k=0;
		for(int m=0;m<n;m++)
		{
			int vt;
			s(vt);
			int i;
			double max = 0.0;
			struct vertex b;
		
			for(i=0;i<vt;i++)
			{
				sl(v[i].x),sl(v[i].y);
				
				if(dist(v[i])>max)
					max=dist(v[i]);
			}
		//	cout<<max<<" ";
			poly[k].maxd=max;
			poly[k].po=k;
	
			k++;
		}
		sort(poly,poly+n,vcompare);
		for(int i=0;i<n;i++)
		{
			poly[i].num=i;
		}
		sort(poly,poly+n,pocompare);
	
		k=0;
		//for(int i=0;i<n;i++)
		{
			for(k=0;k<n;k++)
				{
					//if(poly[k].po==i)
					{
						printf("%d ",poly[k].num);
					//	break;
					}
			}
		}
		printf("\n");
	//	cout<<"xxx";
		
	}
}

