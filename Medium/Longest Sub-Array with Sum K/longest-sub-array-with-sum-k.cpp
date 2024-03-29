//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
       int ans=0;
        unordered_map<int,int> prefix;
        
        int sum=0;
        
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            
            if(sum==K) ans=max(ans,i+1);
            
            if(prefix.find(sum-K)!=prefix.end())
            {
                int ind=prefix[sum-K];
                if(ind<=i) ans=max(ans,i-ind);
            }
            
            if(prefix.find(sum)==prefix.end()) prefix[sum]=i;
        }
        
        return ans;
        
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends