// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

int dynamic(int arr[], int n){

    // cout << endl << endl;
    int  i, j, k, res, left, right, curr;
    vector<vector<int>> results(n, vector<int>(n, 0));

    //i represents end (cols)
    for(i=2; i<n; ++i){
        // cout << "i : " << i << endl;

        //j represents start (rows)
        for(j=i-2; j>=0; --j){
            // cout << "    j : " << j << endl;
            if(i-j==2){
                results[j][i] = arr[i]*arr[j]*arr[j+1];
                continue;
            }
            res = INT_MAX;
            for(k=j+1; k<i; ++k){

                // cout << "        k : " << k << endl;
                left = results[j][k];
                right = results[k][i];

                curr = left + right + arr[k]*arr[i]*arr[j];
                res=min(res, curr);
            }
            results[j][i]=res;
        }

        // cout << endl << endl;
    }
    return results[0][n-1];
}
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return dynamic(arr, N);
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