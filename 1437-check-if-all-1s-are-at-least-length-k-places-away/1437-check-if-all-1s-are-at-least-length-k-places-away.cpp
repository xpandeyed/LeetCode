class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        long long int n=nums.size(), i, dis=INT_MAX;
        for(i=0; i<n; ++i){
            if(nums[i]==1 && dis<k){
                return false;
            }
            if(nums[i]==1){
                dis=0;
            }else{
                dis++;
            }   
        }
        return true;
    }
};