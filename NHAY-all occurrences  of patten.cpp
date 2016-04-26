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
      //cout<<z[i];
   }
   int count=0;
   for(int i=len;i<n;i++)
   {
   	if(z[i]==len)cout<<i-len-1<<endl;
   }
   cout<<endl;
}
 
int main() {
  int len;
  char s1[100550],s2[100550];
  string text,pat;
  while(scanf("%d",&len)){
  	scanf("%s %s",s1,s2);
  	pat=s1,text=s2;
    pat.append("&");
    pat.append(text);
   // cout<<pat;
    compute_z(pat,len);
   
  }
  return 0;
}
