//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int fit(int a,int b){
        if(a>b){
            a = a/2;
            return 1 + fit(a,b);
        }
        else if(a <= b){
            return 0;
        }
    }

    int carpetBox(int A, int B, int C, int D){
        //code here
        int ans = 0;
        int a = A;
        int b = B;
        int c = C;
        int d = D;
        int ans1 = fit(a,c) + fit(b,d);
        int ans2 = fit(a,d) + fit(b,c);
        return min(ans1 , ans2);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends