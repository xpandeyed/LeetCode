class Solution {
public:
        int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), i, count=1, j=0;
        for(i=1; i<n; ++i){
            if(nums[i]==nums[j]){
                count++;
            }
            else{
                count=1;
            }
            if(count>=3){
                continue;
            }else{
                j++;
                swap(nums[i], nums[j]);
            }
        }
        return j+1;
    }
    
    int binarySearch(vector<int> nums, int start, int end, int target){
        while(start<=end){
            int m=(start+end)/2;
            if(nums[m]==target){
                return m;
            }else if(nums[m]>target){
                end--;
            }else{
                start++;
            }
        }
        
        return -1;
    }
    
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = removeDuplicates(nums), i, res = 0;
        //cout << n << endl;
        for(i=0; i<n; ++i){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            if(binarySearch(nums, i+1, n-1, nums[i]+k)!=-1){
                res++;
            }
        }
        
        return res;
        
        
    }
};