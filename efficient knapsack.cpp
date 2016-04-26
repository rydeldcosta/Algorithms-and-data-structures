#include<bits/stdc++.h>
#include<vector>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define lli long long int
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define max(x,y) (x>y)?x:y;
using namespace std;

/*struct item
{
	int idx;
	lli val,mincost;
};*/
//vector<struct item> v;
/*bool cmp(struct item a,struct item b)
{
	return a.val<b.val;
}*/
long long int knapSack( int S, int N,int wei[],lli value[] ) {
	lli i, w;
	long int K[ 2 ][ S + 1 ];

 i=0;
    while(++i <= N)
    {
        int j = 0;

        if(i%2)
        {
            while(++j <= S)
            {
                if(wei[i-1] <= j)
                {
                    K[1][j] = max( value[i-1] + K[0][ j-wei[i-1] ] , K[0][j] );
                }
                else
                    K[1][j] = K[0][j];
            }

        }

        else
        {
            while(++j <= S)
            {
                if(wei[i-1] <= j){
                
                    K[0][j] = max( value[i-1] + K[1][ j-wei[i-1] ] , K[1][j] );
                }
                else
                    K[0][j] = K[1][j];
            }

        }
    }
//	for(int i=0;i<=N;i++)
	{
//		cout<<K[i][S]<<" ";
	}
	if(N&1)
		return K[ 1 ][ S ];
	else
		return K[0][S];

}
int main()
{
	int t;
	//cout<<"sas";
	s(t);
//	struct item tmp;
	while(t--)
	{
		//cout<<"sas";
		//v.clear();
		lli n,k,m;
		sl(n),sl(k),sl(m);
		lli ar[n],sum=0,value[n];
		int wei[n],weit[n];
		int w1=0,v1=0;
		for(lli i=0;i<n;i++)
		{
			sl(ar[i]);
			sum+=ar[i];
			ar[i]*=-1;
			if(ar[i]>0)
			{
				value[v1++]=ar[i];
			}
			wei[i]=INT_MAX;
			
		}

		for(int i=0;i<m;i++)
		{
			int l,r,ct;
			s(l),s(r),s(ct);

			for(int j=l-1;j<r;j++)
			{
				wei[j] = min(wei[j],ct);
			}
		//	cout<<"a";
		}
		for(int i=0;i<n;i++)
		{
			if(ar[i]>0)
				weit[w1++] = wei[i];
		}
	//	sort(all(v),cmp);
	//	cout<<"sas";
//	for(int i=0;i<w1;i++)
//		cout<<value[i]<<" ";
	cout<<sum+knapSack(k,w1,weit,value)<<endl;

		
	}
}
