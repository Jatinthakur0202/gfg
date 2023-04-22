//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    // code here
        //need to find anagrams of pat in txt
        int count = 0;
        int n = txt.length();
        int m = pat.length();
        int i=0;
        int j=0;
        int pat_count[26]={0};
        int txt_count[26]={0};
        for(int i=0;i<m;i++){
            pat_count[pat[i]-'a']++;
        }
        while(j<n){
            txt_count[txt[j]-'a']++;
            if(j-i+1<m){
                j++;
            }
            else if(j-i+1==m){
                bool flag = true;
                for(int i=0;i<26;i++){
                    if(pat_count[i]!=txt_count[i]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    count++;
                }
                txt_count[txt[i]-'a']--;
                i++;
                j++;
            }
        }
        return count;
	}
        

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends