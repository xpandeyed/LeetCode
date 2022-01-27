// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    	int i, j, ma=arr[0];
	vector<int> res(arr, arr+n);
	res[0]=arr[0];
	for(i=1; i<n; ++i){
		j=0;
		while(j<i){
			if(arr[i]>arr[j] && res[j]+arr[i]>res[i]){
				res[i]=res[j]+arr[i];
				ma=max(res[i], ma);
			}
			j++;
		}
	}
	return ma;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends