#include <string>
#include <cstdio>
#include <vector>
#include <iostream>						//Z ALGORITHM :D
#include <algorithm>
using namespace std;
 
long long compute_z(string s,int len){
   long long sum=0;
   int n = s.length();
   vector<int> z(n,0);
	z[0] = n;
	 
   long long L = 0, R = 0;
   for (long long i = 1; i < n; i++) {
      if (i > R) {
         L = R = i;													//setting the bounds of the z-box
         while (R < n && s[R-L] == s[R]) R++;
         z[i] = R-L; R--;
      }
 
      else {
 
         int k = i-L;
         if (z[k] < R-i+1) z[i] = z[k];					//r-i+1 = beta
         else {
            L = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
         }
      }
     // cout<<z[i];
   }
   //return sum;
   long long cnt=0;
   for(int i=len;i<n;)
   {
   	if(z[i]==len){
   	cnt++;i+=len;continue;}
   	i++;
   }
   return cnt;
}
 
int main() {
  int t; string s; long long sum;
  cin>>t;getchar();
  while(t--){
    cin>>s;
    long long g = s.size();
    int n,m;
    cin>>n>>m;
    string p = "",q="";
    for(int i=0;i<n;i++)
    {
    	p.append("a");
    }
    for(int i=0;i<m;i++)
    {
    	q.append("b");
    }
    q.append("$");
    q.append(s);
    p.append("$");
    p.append(s);
    long long x = compute_z(p,n);
    //int y = compute_z(q,m);
    long long ans = s.size()-x*(n-m);
    cout<<min(g,ans)<<" "<<max(g,(ans))<<endl;
   // cout<<compute_z(s)+s.size()<<endl;
   
  }
  return 0;
}
