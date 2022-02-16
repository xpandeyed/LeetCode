class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size(), start=0, end, mid;
        end=n-1;
        while(start<=end){
            mid = (start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target ){
                if(mid==n-1 || nums[mid+1]>target){
                    return mid+1;
                }else{
                    start=mid+1;
                }
            }
            else{
                if(mid==0 || nums[mid-1]<target){
                    return mid;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
        
    }
};