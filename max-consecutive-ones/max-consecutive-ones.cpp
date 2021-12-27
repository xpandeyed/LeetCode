class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        int count = 0;
        for(int i=0; i<n ; ++i){
            if(nums[i]==0){
                count=0;
                continue;
            }
            count++;
            res=max(res, count);
        }
        return res;
    }
};