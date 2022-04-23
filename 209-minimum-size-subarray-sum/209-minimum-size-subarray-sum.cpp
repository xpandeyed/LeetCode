class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0, n=nums.size(), len=INT_MAX, sum=0;
        while(r<n){
            sum+=nums[r++];
            while(sum>=target){
                len=min(len, r-l);
                sum-=nums[l++];
            }
        }
        return len==INT_MAX?0:len;
        
    }
};