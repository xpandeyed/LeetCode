class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(), i, product=nums[0], res=0, start=0;
        if(product<k) res++;
        for(i=1;i<n;++i){
            product*=nums[i];
            while(product>=k and start<=i){
                product/=nums[start++];
            }
            int ele = i-start+1;
            res+=ele;
            
        }
        return res;
    }
};