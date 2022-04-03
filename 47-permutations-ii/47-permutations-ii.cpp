class Solution {
public:
    void rec(int i, int j, vector<int> nums, vector<vector<int>> &res){
        if(i==j-1){
            res.push_back(nums);
            return ;
        }
        set<int> s;
        for(int k=i; k<j; ++k){
            if((i!=k and nums[i]==nums[k]) or s.find(nums[k])!=s.end()) continue;
            s.insert(nums[k]);
            swap(nums[i], nums[k]);
            rec(i+1, j, nums, res);
            swap(nums[i], nums[k]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        rec(0, nums.size(), nums, res);
        return res;
    }
};