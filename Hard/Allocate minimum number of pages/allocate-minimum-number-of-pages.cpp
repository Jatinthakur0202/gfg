//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
        bool isPossible(int A[], int N, int M, int curr_min)
    {
        int studentsRequired = 1;
        int curr_sum = 0;
        for(int i = 0; i < N; i++)
        {
            if(A[i] > curr_min)
                return false;
            if(curr_sum + A[i] > curr_min)
            {
                studentsRequired++;
                curr_sum = A[i];
                if(studentsRequired > M)
                    return false;
            }
            else
                curr_sum += A[i];
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
           if(M > N)
            return -1;
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum += A[i];
        int start = 0, end = sum, res = INT_MAX;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(isPossible(A, N, M, mid))
            {
                res = min(res, mid);
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends