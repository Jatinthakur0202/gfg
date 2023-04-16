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
   
  long long solve(int N, vector<int> &A, vector<int> &B) {
        vector<int> oddA, oddB, evenA, evenB;
        
        long sum1 = 0, sum2 = 0;
        
        for (int i = 0; i < N; i++) {
            sum1 += A[i];
            sum2 += B[i];
            
            if (A[i] % 2 == 0) evenA.push_back(A[i]);
            else oddA.push_back(A[i]);
            
            if (B[i] % 2 == 0) evenB.push_back(B[i]);
            else oddB.push_back(B[i]);
        }
        
        if (sum1 != sum2 || oddA.size() != oddB.size()) return -1;
        
        long ans = 0;
        
        sort(oddA.begin(), oddA.end()); 
        sort(oddB.begin(), oddB.end());
        sort(evenA.begin(), evenA.end()); 
        sort(evenB.begin(), evenB.end());
        
        for (int i = 0; i < oddA.size(); i++)
            ans += abs(oddA[i] - oddB[i]) / 2;
        
        for (int i = 0; i < evenA.size(); i++)
            ans += abs(evenA[i] - evenB[i]) / 2;
        
        return ans / 2;
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
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends