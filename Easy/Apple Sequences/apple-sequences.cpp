//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here
         int i=0,j=0,c=0,t=0;
        while(j<arr.length()){
            if(arr[j]=='O') c+=1;
            if(c<=m) t=max(t,j-i+1);
            else{
                while(c>m){
                    if(arr[i]=='O') c--;
                    i++;
                }
            }
            j++;
        }
        return t;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends