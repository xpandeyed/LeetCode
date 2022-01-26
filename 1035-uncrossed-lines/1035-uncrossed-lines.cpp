class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2, int i1, int i2, vector<vector<int>> &res){
        if(i1==nums1.size() || i2==nums2.size()){
            return res[i1][i2] = 0;
        }
        if(res[i1][i2]!=-1){
            return res[i1][i2];
        }
        if(nums1[i1]==nums2[i2]){
            return res[i1][i2] =max(1+helper(nums1, nums2, i1+1, i2+1, res), max(helper(nums1, nums2, i1, i2+1, res), helper(nums1, nums2, i1+1, i2, res)));
        }else{
            return res[i1][i2] =max(helper(nums1, nums2, i1, i2+1, res), helper(nums1, nums2, i1+1, i2, res));
        }
        return res[i1][i2];
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(nums1.size()+1, vector<int>(nums2.size()+1, -1));
        return helper(nums1, nums2, 0, 0, res);
    }
};