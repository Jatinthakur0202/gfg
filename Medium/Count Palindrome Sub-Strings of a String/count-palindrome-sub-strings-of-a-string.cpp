//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int tabu(string a,int len){

        

        vector<vector<int>> dp(len,vector<int>(len,0));

        

        int diff=0;

        // storing answer

        int count=0;

        

        for(;diff<len;diff++){

            

            for(int i=0,j=i+diff;i<len &&  j<len;i++,j++){

                

                if(i == j){

                   dp[i][j]=1; 

                }

                

                else if(j - i == 1 && a[i] == a[j]){

                    dp[i][j]=(a[i] == a[j])?2:0;

                }

                

                else if(a[i] == a[j] && dp[i+1][j-1] != 0){

                

                    if(a[i] == a[j]){

                        dp[i][j]=dp[i+1][j-1]+2;
                    }
                    else dp[i][j]=0;
                }
                if(dp[i][j] >=2){
                count++;
                }
            }
        }    
       return count;
    }

int CountPS(char S[], int N)

{
    string s="";
    for(int i=0;i<N;i++){
        s+=S[i];
    }
    return tabu(s,N);
}
    