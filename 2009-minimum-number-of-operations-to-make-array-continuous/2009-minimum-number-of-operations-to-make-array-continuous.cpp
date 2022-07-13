class Solution {
public:
    int minOperations(vector<int>& nums) {
        //ws = window start, we = window end
        //for every element consider it as start of window
        int n=nums.size(), i, res=INT_MAX, ws, we, j=0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(begin(nums), end(nums)), end(nums));
        int n2=nums.size();
        const int diff = n-1;
        for(i=0;i<n2;++i){
            //array may contain duplicates so this line will be saviour
            if(i>0 and nums[i]==nums[i-1]) continue;
            ws = nums[i];
            we = nums[i]+diff;
            while(j<n2 and nums[j]<=we) j++;
            //from i to j-1 we have got elements which do not need to be replaced
            res = min(res, n-(j-i));
            if(res==0) return 0;
        }
        return res;
    }
};