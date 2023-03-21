//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    bool isScramble(string S1, string S2){
        //code here
         if(S1.length() != S2.length())
            return false;
        if(S1.length() == 0 || S1 == S2)
            return true;
        int n = S1.length();
        bool dp[n][n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j][0] = (S1[i] == S2[j]);
            }
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                for(int j=0;j<=n-len;j++){
                    dp[i][j][len-1] = false;
                    for(int k=1;k<len;k++){
                        if((dp[i][j][k-1] && dp[i+k][j+k][len-k-1]) || (dp[i][j+len-k][k-1] && dp[i+k][j][len-k-1])){
                            dp[i][j][len-1] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n-1];
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends