class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i;
        int diff1=0, diff2=INT_MAX;
        if(n%2==0){
            diff2=0;
        }
        for(i=0; i<n;++i){
            diff1+=abs(nums[i]-nums[n/2]);
            if(n%2==0){
                diff2+=abs(nums[i]-nums[n/2-1]);
            }
        }
        return min(diff1, diff2);
    }
};
