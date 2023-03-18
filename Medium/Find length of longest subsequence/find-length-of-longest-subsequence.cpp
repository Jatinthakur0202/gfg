//{ Driver Code Starts
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
 
int maxSubsequenceSubstring(string x, string y, int n, int m);
 
// Driver Program
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        string x,y;
        cin>>n>>m;
        cin>>x>>y;
        cout<<maxSubsequenceSubstring(x,y,n,m)<<"\n";
    }
    return 0;
}
// } Driver Code Ends


int maxSubsequenceSubstring(string s1, string s2, int n, int m){
    //code
     
       int dp[n+1][m+1];
        int mm = 0;
        for(int i=0;i<=n;i++){
            for(int j =0;j<=m;j++){
                if(i==0||j==0)
                    dp[i][j] = 0;
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] =  1 + dp[i-1][j-1];
                     mm = max(mm, dp[i][j]);
                }
                else{
                dp[i][j] = dp[i - 1][j];
                    
                }
            }
        }
        return mm;
     
}