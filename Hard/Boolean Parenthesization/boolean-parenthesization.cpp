//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
        int t[201][201][2]; 
    int solve(string str, int i, int j, bool istrue){
        if(i>j)
            return 0;
        if(i==j){
            if(istrue)
                return str[i]=='T';
            else
                return str[i]=='F';
        }
        if(t[i][j][istrue] != -1) 
          return t[i][j][istrue];
        int ans = 0;
        for(int k=i+1;k<j;k+=2){
            int lt = solve(str, i, k-1, true);
            int lf = solve(str, i, k-1, false);
            int rt = solve(str, k+1, j, true);
            int rf = solve(str, k+1, j, false);
            if(str[k]=='&'){
                if(istrue)
                    ans += lt*rt;
                else
                    ans += lt*rf + lf*rt + lf*rf;
            }
            else if(str[k]=='|'){
                if(istrue)
                    ans += lt*rt + lt*rf + lf*rt;
                else
                    ans += lf*rf;
            }
            else if(str[k]=='^'){
                if(istrue)
                    ans += lt*rf + lf*rt;
                else
                    ans += lt*rt + lf*rf;
            }
        }
        return t[i][j][istrue] = ans % 1003;
    }
    int countWays(int N, string S){
        // code here
        memset(t, -1, sizeof(t));
        return solve(S, 0, N-1, true);
      
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends