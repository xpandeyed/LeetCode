class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int h=nums.size()-1;
        for(int i=0; i<nums.size() && i<=h; ++i){
            while(h>0 && nums[h]==val){
                h--;
            }
            if(h==0 && nums[h]==val){
                return 0;
            }
            if(nums[i]==val&& i<h){
                swap(nums[i], nums[h]);
                h--;
            }
        }
        return h+1;
    }
};