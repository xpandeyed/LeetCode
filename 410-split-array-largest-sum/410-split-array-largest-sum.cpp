class Solution {
public:
    int ok(vector<int> &nums, int mid, int n, int m){
        int i, total=0, subArrays=0;
        for(i=0; i<n; ++i){
            if(nums[i]>mid){
                return false;
            }else if(total+nums[i]<=mid){
                total+=nums[i];
            }else{
                subArrays++;
                total=nums[i];
            }
        }
        subArrays++;
        return subArrays<=m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l=0, r=(int)(1e9 +1), mid, n=nums.size();
        while(l<=r){
            mid=(l+r)/2;
            if(ok(nums, mid, n, m)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        
        return l;
    }
};