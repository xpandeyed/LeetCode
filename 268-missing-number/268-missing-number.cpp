class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(), allXors=0, i;
        for(i=0; i<=n; ++i){
            allXors^=i;
        }
        
        for(i=0; i<n; ++i){
            allXors^=nums[i];
        }
        
        return allXors;
    }
};