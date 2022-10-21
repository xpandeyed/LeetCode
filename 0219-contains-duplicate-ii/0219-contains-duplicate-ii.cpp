class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        int i=0, n=nums.size();
        while(i<n){
            if(m.find(nums[i])==m.end() or abs(m[nums[i]]-i)>k){
                m[nums[i]]=i;
                i++;
                continue;
            }
            return true;
        }
        return false;
    }
};