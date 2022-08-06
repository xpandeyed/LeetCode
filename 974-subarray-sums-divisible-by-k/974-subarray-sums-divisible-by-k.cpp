class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res=0, n=nums.size(), i, rem;
        map<int,int> m;
        m[0]=1;
        for(i=0;i<n;++i){
            if(i>0) nums[i]+=nums[i-1];
            rem = nums[i]%k;
            if(rem<0) rem+=k;
            res+=m[rem];
            m[rem]++;
        }
        
        return res;
    }
};