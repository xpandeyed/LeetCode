class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size(), l=0, h=n-1, m;
        if(n==1){
            return target==nums[0];
        }
        while(l<=h){
            m=(l+h)/2;
            // cout << l << " " << m << " "  << h << endl;
            if(nums[m]==target){
                return true;
            }
            if(nums[l]==nums[m] and nums[m]==nums[h]){
                l++;
                h--;
            }else if(nums[l]<=nums[m]){
                if(target>=nums[l] and target<=nums[m]){
                    h=m;
                }else{
                    l=m+1;
                }
            }else{
                if(target>=nums[m+1] and target<=nums[h]){
                    l=m+1;
                }
                else{
                    h=m;
                }
            }
        }
        return false;
    }
};