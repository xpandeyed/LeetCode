class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n=nums.size(), l=0, m, h=n-k, s;
        while(l<h){
            m=(l+h)/2;
            if(x-nums[m]>nums[m+k]-x){
                l=m+1;
            }else{
                h=m;
            }
            
        }
        vector<int> res;
        s=0;
        while(s<k){
            res.push_back(nums[l++]);
            s++;
        }
        
        return res;
    }
};