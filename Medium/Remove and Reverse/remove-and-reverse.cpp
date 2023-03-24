//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here     
        unordered_map<char,int> m;
        for(int i=0;i<S.length();i++){
            m[S[i]]++;
        }
        int start = 0;
        int dir = 0;
        int end = S.length()-1;

        while(start<end){
                if(dir == 0){
                    if(m[S[start]] == 1){
                        start++;
                    }
                    else{
                        m[S[start]]--;
                        dir = 1;
                        S[start] = 'A';
                        start++;
                    }
                }
                else{
                    if(m[S[end]] == 1){
                        end--;
                    }
                    else{
                        m[S[end]]--;
                        dir = 0;
                        S[end] = 'A';
                        end--;
                    }
                }
        }
        string ans = "";
        if(dir ==1){
            for(int i=S.length()-1;i>=0;i--){
                if(S[i] != 'A')
                    ans += S[i];
            }
        }
        else{
            for(int i=0;i<S.length();i++){
                if(S[i] != 'A')
                    ans += S[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends