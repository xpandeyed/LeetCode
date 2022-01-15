class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        int i=0, n=nums.size(), m=nums[0];
        for(i=0; i<n ; ++i){
            s.insert(nums[i]);
            m=max(m, nums[i]);
        }
        if(s.size()>=3){
            return *(------s.end());
        }
        return m;
    }
};