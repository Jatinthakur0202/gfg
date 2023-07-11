//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

string Country_at_war(int a[], int b[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+1], b[n+1];

        for(int i=0;i<n;i++)
            cin>> a[i];
        
        for(int i=0;i<n;i++)
            cin>> b[i];

        cout << Country_at_war(a, b, n) << endl;

    }
    return 0;
}

// } Driver Code Ends


string Country_at_war(int a[], int b[], int n)
{
    // Complete the function
   int s{};
    while ( n-- )
        s += ( a[ n ] > b[ n ] ) - ( a[ n ] < b[ n ] );
    return !s ? "DRAW" : s > 0 ? "A" : "B";
}
