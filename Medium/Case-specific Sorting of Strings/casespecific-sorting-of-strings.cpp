//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
         vector<char> upper;
        vector<char> lower;
        for(int i=0;i<n;i++){
            if(str[i]>='A' && str[i]<='Z'){
                upper.push_back(str[i]);
            }
            else{
                lower.push_back(str[i]);
            }
        }
        sort(upper.begin(),upper.end());
        sort(lower.begin(),lower.end());
        int j=0,k=0;
        for(int i=0;i<n;i++){
            if(str[i]>='A' && str[i]<='Z'){
                str[i]=upper[j];
                j++;
            }
            else{
                str[i]=lower[k];
                k++;
            }
        }
        return str;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends