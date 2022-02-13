class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        res.push_back(temp);
        int n=nums.size(), i, s, k;
        for(i=0; i<n;++i){
            s = res.size();
            for(k=0; k<s; ++k){
                temp = res[k];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        
        return res;
        
        
    }
};