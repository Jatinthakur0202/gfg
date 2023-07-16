//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
  public:
    int rightmostNonZeroDigit(int N, int A[]){
       int count5 = 0;
        int count2 = 0;
        int extra = 1;
        for(int i=0;i<N;i++){
            int val = A[i];
            if(val == 0)
                return -1;
            while(val%5 == 0){
                count5++;
                val /= 5;
            }
            while(val%2 == 0){
                count2++;
                val /= 2;
            }
            extra = (extra * val)%10;
        }
        int count0 = min(count2,count5);
        if(count0 < count5){
            for(int i=0;i<count5-count0;i++){
                extra = (extra * 5)%10;
            }
        }
        if(count0 < count2){
            for(int i=0;i<(count2-count0);i++){
                extra = (extra * 2)%10;
            }
        }
        return extra;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        Solution ob;
        cout << ob.rightmostNonZeroDigit(n, A) << endl;
    }
    return 0; 
} 
// } Driver Code Ends