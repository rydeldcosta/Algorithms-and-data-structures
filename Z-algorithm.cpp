#include <string>
#include <cstdio>
#include <vector>
#include <iostream>						//Z ALGORITHM :D
#include <algorithm>
using namespace std;
 
long long compute_z(string s){
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
      cout<<z[i];
   }
   //return sum;
}
 
int main() {
  int t; string s; long long sum;
  cin>>t;getchar();
  while(t--){
    cin>>s;
    compute_z(s);
   // cout<<compute_z(s)+s.size()<<endl;
   
  }
  return 0;
}
