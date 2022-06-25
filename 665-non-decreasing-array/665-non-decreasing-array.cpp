class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int m, i, n=nums.size(); //m means modifications
        for(i=1;i<n;++i){
            if(nums[i-1]>nums[i]){
                if(i-2>-1 and nums[i-2]>nums[i]){
                    nums[i]=nums[i-1];
                }
                else{
                    nums[i-1]=nums[i];
                }
                m++;
            }
        }
        return m<2;
    }
};