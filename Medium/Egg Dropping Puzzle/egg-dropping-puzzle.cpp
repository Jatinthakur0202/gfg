//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        int dp[n + 1][k + 1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= k; j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(i == 1) dp[i][j] = j;
                else if(j == 1) dp[i][j] = 1;
                else{
                    int ans = INT_MAX;
                    for(int x = 1; x <= j; x++){
                        int temp = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                        ans = min(ans, temp);
                    }
                    dp[i][j] = ans;
                }
            }
        }
        return dp[n][k];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends