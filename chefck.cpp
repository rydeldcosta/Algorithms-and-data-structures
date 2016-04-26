#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<deque>
#define S(x) scanf("%d",&x)
#define SLL(x) scanf("%lld",&x)
#define P(x) printf("%d",x)
#define PLL(x) printf("%lld",x)
#define lli long long int 
#define MOD 1000000007
#define pb(x) push_back(x)
using namespace std;
vector<lli> v;
lli B[10000004];
void minSlidingwindow(lli n, lli k)
{
	deque<lli> dq;
	for(lli i= 1;i<=k;i++)				//processses first k elements
	{
		while(!dq.empty() && v[i]<=v[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}
	for(lli i = k;i<=n;i++)
	{
		B[i-k] = v[dq.front()];
		
		while(!dq.empty() && v[i]<=v[dq.back()])
			dq.pop_back();
		while(!dq.empty() && dq.front()>=i-k)
			dq.pop_front();
		dq.push_back(i);
	}
	B[n-k]  = v[dq.front()];
	
}

int main()
{
	lli n,k,q;
	SLL(n);SLL(k);SLL(q);
	lli a,b,c,d,e,f,r,s,t,m,Lm,Dm,La,Da,Lc,Dc,L1,D1,z,L,R;
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&z);
	v.pb(0);//buffer
	v.pb(z);
	for(long long i = 2;i<=n;i++)
	{
		t = (t*i)%s;
		if( t<= r)
			v.pb((a*v[i-1]*v[i-1]+b*v[i-1]+c)%m);
		else
			v.pb((d*v[i-1]*v[i-1]+e*v[i-1]+f)%m);
	}
	//L1, La, Lc, Lm, D1, Da, Dc, and Dm;
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&L1,&La,&Lc,&Lm,&D1,&Da,&Dc,&Dm);
	for(long long i = 1;i<=q;i++)
	{
		L1 = (La * L1 + Lc)%Lm;
		D1 = (Da * D1 + Dc)%Dm; 
		L = L1 + 1;
		R = min(L + k - 1 + D1, n);
	}
	vector<lli>::iterator it1,it2;
	it1 = v.begin()+L,it2=v.begin()+R+1;
	lli sum=0, product = 1,ans;
	for(lli i=1;i<=q;i++)
	{
		ans = min(B[L-1], B[R-k+1-1]);
		
		sum+=ans;
		product*=ans%MOD;
		//*min_element(it1,it2+1) = 999999999; 
		
	}
	printf("%lld %lld\n", sum, product);
}
