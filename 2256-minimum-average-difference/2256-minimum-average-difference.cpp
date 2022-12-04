class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int i, minDiff=INT_MAX, l=0, r=0, n=nums.size(), res, diff;
        for(i=n-1; i>-1; --i){
            r+=nums[i];
        }
        for(i=0;i<n; ++i){
            l+=nums[i];
            r-=nums[i];
            
            if((n-i-1)){
                diff=abs((l/(i+1)) - (r/(n-i-1)));
            }
            else diff=abs(l/(i+1));
            if(diff<minDiff){
                res=i;
                minDiff=diff;
            }
        }
        return res;
    }
};