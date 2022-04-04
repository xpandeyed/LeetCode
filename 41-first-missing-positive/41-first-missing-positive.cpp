class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        int n=nums.size(), i;
        for(i=0; i<n; i++){
            if(nums[i]<1 or nums[i]>=n){
                nums[i]=0;
            }
        }
        
        for(i=0; i<n; ++i){
            nums[nums[i]%n]+=n;
        }
        
        for(i=1; i<n; ++i){
            if(nums[i]<n){
                return i;
            }
        }
        
        return i;
    }
};