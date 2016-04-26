/*
  longest palindrome subsequence (optimum)
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility> 
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vii;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define len length()
#define rep(i,n) for(int i=0;i<n;i++)
#define ref(i,a,n) for(int i=a;i<=n;i++)
#define reb(i,n,a) for(int i=n;i>=a;i--)
#define all(a) a.begin(),a.end()
#define gi(n) scanf("%d",&n)
#define pi(n) printf("%d",n)
#define ps printf(" ")
#define pn printf("\n")

char str[100000];

int main()
{
        int n,ans=0;
        scanf("%d",&n);
        scanf("%s",str);
        int dp[2][100000];
        int *prev=dp[0],*cur=dp[1];
        ref(i,1,n) {
                ref(j,1,n) {
                        if(str[i-1]==str[n-j]) cur[j]=1+prev[j-1],ans=max(cur[j],ans);
                        else cur[j]=0;
                }
		int *temp;
                temp=prev;
                prev=cur;
                cur=temp;	
        }
        pi(n-ans);pn;
        return 0;
}

