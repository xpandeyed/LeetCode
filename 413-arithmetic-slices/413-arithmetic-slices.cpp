class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(), res=0, i, diff, count;
        
        if(n<3){
            return 0;
        }
        
        diff=nums[1]-nums[0];
        
        count=2;
        
        for(i=2; i<n; ++i){
            if(nums[i]-nums[i-1]==diff){
                count++;
            }else{
                count = 2;
                diff = nums[i]-nums[i-1];
            }
            
            if(count>2){
                res+=(count-2);
            }
            
        }
        
        return res;
        
        
    }
};