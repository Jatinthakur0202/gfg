//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            
            String St[] = read.readLine().split(" ");
            
            int N = Integer.parseInt(St[0]);
            int K = Integer.parseInt(St[1]);
            
            String S[] = read.readLine().split(" ");
            
            int[] arr = new int[N];
            
            for(int i=0 ; i<N ; i++)
                arr[i] = Integer.parseInt(S[i]);

            Solution ob = new Solution();
            System.out.println(ob.splitArray(arr,N,K));
        }
    }
}
// } Driver Code Ends


class Solution {
  static int noOfPartitions(int arr[],int sum){
        // code here
         int currSum=0,partitions=1;
        for(int i:arr){
            if(currSum+i<=sum) currSum+=i;
            else{
                partitions++;
                currSum=i;
            }
        }
        return partitions;
    }
    static int splitArray(int[] arr , int N, int K) {
        // code here
        int minPossible=Integer.MIN_VALUE,maxPossible=0;
        for(int i:arr){
            minPossible=Math.max(minPossible,i);
            maxPossible+=i;
        }
        int l=minPossible,r=maxPossible;
        while(l<=r){
            int mid=(l+r)/2;
            int currPartitions=noOfPartitions(arr,mid);
            if(currPartitions<=K) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};