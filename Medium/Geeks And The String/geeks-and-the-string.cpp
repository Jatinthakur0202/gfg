//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      string remove_consecutive_duplicates(string s) {

    string res = "";

    for (int i = 0; i < s.length(); i++) {

        if (i + 1 < s.length() && s[i] == s[i + 1]) {

            i++; // Skip the next character

        } else {

            res += s[i];

        }

    }

    return res;

}

    string removePair(string s) {

        // code here

            string res = remove_consecutive_duplicates(s);

    if (res.length() == s.length()) {

        return res;

    }

    else if(res.length()==0)

    {

        return "-1";

    } 

    else{

        return removePair(res);

    }

   

    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends