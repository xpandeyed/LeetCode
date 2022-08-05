class Solution {
public:
    map<int, int> m;
    int rec(vector<int>& nums, int target){
        // cout << target << endl;
        if(m.find(target)!=m.end()) return m[target];
        if(target==0) return m[target]=1;
        if(nums[0]>target) return m[target]=0;
        int res = 0;
        for(int &x: nums){
            res+=rec(nums, target-x);
        }
        return m[target]=res;
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return rec(nums, target);
    }
};