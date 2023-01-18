//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n = s.length();
        int m = p.length();
        if(n < m)
            return "-1";
        int hash_pat[256] = {0};
        int hash_str[256] = {0};
        for(int i = 0; i < m; i++)
            hash_pat[p[i]]++;
        int start = 0, start_index = -1, min_len = INT_MAX, count = 0;
        for(int j = 0; j < n; j++)
        {
            hash_str[s[j]]++;
            if(hash_pat[s[j]] != 0 && hash_str[s[j]] <= hash_pat[s[j]])
                count++;
            if(count == m)
            {
                while(hash_str[s[start]] > hash_pat[s[start]] || hash_pat[s[start]] == 0)
                {
                    if(hash_str[s[start]] > hash_pat[s[start]])
                        hash_str[s[start]]--;
                    start++;
                }
                int len_window = j - start + 1;
                if(min_len > len_window)
                {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }
        if(start_index == -1)
            return "-1";
        return s.substr(start_index, min_len);
    }
    
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends