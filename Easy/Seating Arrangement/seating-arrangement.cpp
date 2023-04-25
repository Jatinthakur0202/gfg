//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here
    
    int curr,prev,next;
     curr=0;
    
    if(n==0) return 1;
    if(m==1){
        if(seats[0]==0) return 1;
        return 0;
    }
    while(curr<m){
        next=curr+1;
        prev=curr-1;
        if(curr==0){
            if(seats[curr]==0 and seats[next]==0){
                seats[curr]=1;
                curr=curr+1;
                n=n-1;
            }
        }
        
        else if(curr==m-1){
            if(seats[prev]==0 and seats[curr]==0){
                n=n-1;
                seats[curr]=1;
                curr=curr+1;
            }
        }
        else if(seats[curr]==0 and seats[prev]==0 and seats[next]==0 ){
            seats[curr]=1;
            n=n-1;
            curr+=1;
        }
        
        if(n==0) return true;
        if(seats[curr]==1 or (next<m and seats[next]==1) or (prev>=0 and seats[prev]==1))curr++;
    }
    return false;
    
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends