class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(), i, fromStart=nums[0], fromEnd=nums[n-1];
        vector<int> res(n, 1);
        for(i=1; i<n; ++i){
            res[i]*=fromStart;
            fromStart*=nums[i];
        }
        for(i=n-2; i>-1; --i){
            res[i]*=fromEnd;
            fromEnd*=nums[i];
        }
        
        return res;
    }
};