// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string s){
		    // Code here	cout << endl;
	vector<vector<string>> results(s.size()+1, vector<string>(s.size()+1, ""));
	int n1 = s.size(), i, j, l ,r;
	for(i=0; i<n1+1; ++i){
		for(j=0; j<n1+1; ++j){
			if(i==0 || j==0){
				results[i][j]="";
				continue;
			}
			if(s[i-1]==s[j-1] && i!=j){
				results[i][j] = s[i-1]+results[i-1][j-1];
			}else{
				results[i][j] = results[i-1][j].size()>results[i][j-1].size()?results[i-1][j]:results[i][j-1];
			}
		}
	}
	return results[n1][n1].size();
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends