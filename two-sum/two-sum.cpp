class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> s;
        vector<int> res(2, -1);
        int n=nums.size();
        for(int i=0; i<n; ++i){
            if(s.find(target-nums[i])!=s.end()){
                res[0]=i;
                res[1]=(find(nums.begin(), nums.end(), target-nums[i])-nums.begin());
                return res;
            }
            s.insert(nums[i]);
        }
        return res;
    }
};