class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size(), i, ma=nums[0], start=-1, end=-1;
        for(i=1; i<n; ++i){
            if(nums[i]>=ma){
                ma=nums[i];
                continue;
            }
            if(start==-1){
                start=i-1;
            }
            while(start-1>-1 and nums[start-1]>nums[i])start--;
            end = i;
            
        }
        if(start==-1){
            return 0;
        }
        return end-start+1;
        
    }
};