class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size(), i, start, end, pivot, j;
        start=0;
        end=n-1;
        
        do{
            j=start-1;
            pivot = nums[end];
            for(i=start; i<end; ++i){
                if(nums[i]<pivot){
                    j++;
                    swap(nums[j], nums[i]);
                }
            }
            j++;
            swap(nums[end], nums[j]);
            if(j<(n-k)){
                start=j+1;
                continue;
            }
            if(j>(n-k)){
                end=j-1;
            }
        }while(j!=(n-k));
        
        return nums[j];
    }
};