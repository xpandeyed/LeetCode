class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        int n=nums.size(), s=1, i, l, h, m, ma=nums[0];
        res.push_back(nums[0]);
        for(i=1; i<n; ++i){
            if(nums[i]>ma){
                res.push_back(nums[i]);
                s++;
                ma=nums[i];
                continue;
            }
            l=0;
            h=s-1;
            while(l<=h){
                m=(l+h)/2;
                if(res[m]<nums[i]){
                    l=m+1;
                }else if(m!=0 and res[m-1]>=nums[i]){
                    h=m-1;
                }else{
                    break;
                }
            }
            res[m]=nums[i];
            ma=res[s-1];

        }
        return res.size();
    }
};