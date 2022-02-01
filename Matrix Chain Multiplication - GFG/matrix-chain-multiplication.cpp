// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
        
    int helper(int arr[], int start, int end, vector<vector<int>> &results){
        
        if(results[start][end]!=-1){
            return results[start][end];
        }
        
        //only one matrix
        if(end-start==1){
            return results[start][end] = 0;
        }
        
        
        //only two matrices
        if(end-start==2){
            return results[start][end] = arr[start]*arr[start+1]*arr[start+2];
        }
        
        //more than two matrices
        long long int res = INT_MAX, res1, res2, temp;
        for(int i=start+1; i<end; ++i){
            //partition one from start to i
            res1 = helper(arr, start, i, results);
            //partition two from i to end
            res2 = helper(arr, i, end, results);
            
            
            temp = (arr[start]*arr[end]*arr[i]) + res1 + res2;
            
            res = min(res, temp);
            
            
        }
        
        return results[start][end] = res;
        
    }



    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> results(N, vector<int>(N, -1));
        
        return helper(arr, 0, N-1, results);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends