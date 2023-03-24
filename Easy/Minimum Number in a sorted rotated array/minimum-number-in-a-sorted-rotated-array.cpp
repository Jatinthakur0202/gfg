//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        // Your code here
           int l=0,h=high,res=INT_MAX;

        while(l<=h){

            if(res>arr[l])res=arr[l];

            int mid=(l+h)/2;

            if(arr[mid]>=arr[l])l=mid+1;

            else h=mid-1;

            if(arr[mid]<res)res=arr[mid];

        }

        return res;
        
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}
// } Driver Code Ends