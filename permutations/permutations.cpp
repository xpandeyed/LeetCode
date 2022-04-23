class Solution {
public:
    void rec(vector<int> &nums, int i, vector<vector<int>> &res, int n){
        if(i>=(n-1)){
            res.push_back(nums);
            return ;
        }
        
        int k=i;
        for(k=i; k<n; ++k){
            swap(nums[i], nums[k]);
            rec(nums, i+1, res, n);
            swap(nums[i], nums[k]);
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        rec(nums, 0, res, n);
        return res;
    }
};