//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDistinctDifference(int n, vector<int> &nums) {
        // code here
        set<int> a,b;

        vector<int> front(n,0);

        vector<int> back(n,0);

        

        for(int i=0;i<n;i++){

            back[n-i-1]=b.size();

            front[i]=a.size();

            

            a.insert(nums[i]);

            b.insert(nums[n-i-1]);

            

        }

        for(int i=0;i<front.size();i++){

            

            front[i]=front[i]-back[i];

        }

   return front;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends