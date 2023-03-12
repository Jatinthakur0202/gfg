//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
       int countOnes(vector<int> row) {
        //code here
        int low=0, high=row.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(row[mid]==0)
                low=mid+1;
            else{
                if(mid==0||row[mid-1]==0)
                    return row.size()-mid;
                else
                   high=mid-1;
            }
        }
        return 0;
    }
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        int max=0, maxRow=0;
        for(int i=0; i<N; i++)
        {
            int count=countOnes(mat[i]);
            if(count>max)
            {
                max=count;
                maxRow=i;
            }
        }
        vector<int> ans;
        ans.push_back(maxRow);
        ans.push_back(max);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends