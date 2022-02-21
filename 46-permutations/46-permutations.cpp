class Solution {
public:
    void rec(vector<int> &nums, int i, int n, vector<vector<int>> &res){
        if(i==n-1){
            res.push_back(nums);
            return ;
        }
        for(int k=i; k<n; ++k){
            swap(nums[i], nums[k]);
            rec(nums, i+1,n, res);
            swap(nums[i], nums[k]);
        }
        
    }
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        rec(nums, 0, nums.size(), res);
        return res;
    }
};