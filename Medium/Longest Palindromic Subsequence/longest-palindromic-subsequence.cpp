//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string s1) {
        //code here
        
        string s2  = string(s1.rbegin(), s1.rend());
        int n = s1.length();
        int m = n;
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j =0;j<=m;j++){
                if(i==0||j==0)
                    dp[i][j] = 0;
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] =  1 + dp[i-1][j-1];
                }
                else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends