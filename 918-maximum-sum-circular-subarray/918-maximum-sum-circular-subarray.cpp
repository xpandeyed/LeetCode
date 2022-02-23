class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0, i, n=nums.size(), cmin=nums[0], cmax=nums[0], maxSoFar=nums[0], minSoFar=nums[0];
        
        for(i=0; i<n; ++i){
            sum+=nums[i];
        }
        
        for(i=1; i<n; ++i){
            cmax = max(cmax+nums[i], nums[i]);
            maxSoFar = max(maxSoFar, cmax);
            
            cmin = min(cmin+nums[i], nums[i]);
            minSoFar = min(minSoFar, cmin);
        }
        
        if(minSoFar==sum){
            return maxSoFar;
        }
        
        return max(maxSoFar, sum-minSoFar);
    }
    
};