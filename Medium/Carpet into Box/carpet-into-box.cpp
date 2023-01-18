//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
        //code here
      int carpetBox(int A, int B, int C, int D){

        //code here

        int ans1=0;

        int ans2=0;

        int a=A, b=B, c=C ,d=D;

        while(A > C){

            A/=2;

            ans1++;

        }

        while(B >D){

            B/=2;

            ans1++;

        }

        

        while(a> d){

            a/=2;

            ans2++;

        }

        while(b >c){

            b/=2;

            ans2++;

        }

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