//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
   int m=1e9+7;
int help(int i,int j,int n,vector<vector<int>> &a,vector<vector<int>> &dp)
{
    if(i>=n || j>=n)
     return -1e8;
    if(i==n-1 && j==n-1)
     return a[i][j];
    if(dp[i][j]!=-1)
     return dp[i][j];
    else
    {
        if(a[i][j]==1)
         return dp[i][j]=1+help(i,j+1,n,a,dp);
        else if(a[i][j]==2)
         return dp[i][j]=2+help(i+1,j,n,a,dp);
        else
        {
            int r=3+help(i,j+1,n,a,dp);
            int d=3+help(i+1,j,n,a,dp);
            return dp[i][j]=max(r,d);
        }
    }
}
int ways(int i,int j,int n,vector<vector<int>> &a,vector<vector<int>> &dp)
{
    if(i>=n || j>=n)
     return 0;
    if(i==n-1 && j==n-1)
     return 1;
    if(dp[i][j]!=-1)
     return dp[i][j];
    else
    {
        if(a[i][j]==1)
         return dp[i][j]=ways(i,j+1,n,a,dp)%m;
        else if(a[i][j]==2)
         return dp[i][j]=ways(i+1,j,n,a,dp)%m;
        else
        {
            int r=ways(i,j+1,n,a,dp);
            int d=ways(i+1,j,n,a,dp);
            return dp[i][j]=(r%m + d%m)%m;
        }
    }
}
vector<int> FindWays(vector<vector<int>>&mat){
    // Code here
    int n=mat.size();
    vector<vector<int>> dp1(n,vector<int>(n,-1));
    int cnt=ways(0,0,n,mat,dp1);
    if(cnt==0)
     return {0,0};
    vector<vector<int>> dp2(n,vector<int>(n,-1));
    int ans=help(0,0,n,mat,dp2);
    return {cnt,ans};
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends