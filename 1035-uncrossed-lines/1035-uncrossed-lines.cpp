class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        	int n1 = nums1.size(), n2 = nums2.size(), i, j;
	vector<vector<int>> res(n1+1, vector<int>(n2+1, -1));
	for(i=0; i<n1+1; ++i){
		for(j=0; j<n2+1; ++j){
			if(i==0 || j==0){
				res[i][j]=0;
				continue;
			}
			if(nums1[i-1]==nums2[j-1]){
				res[i][j] = max(1+res[i-1][j-1], max(res[i-1][j], res[i][j]));
			}else{
				res[i][j]=max(res[i-1][j], res[i][j-1]);
			}
		}
	}
	return res[n1][n2];
    }
};