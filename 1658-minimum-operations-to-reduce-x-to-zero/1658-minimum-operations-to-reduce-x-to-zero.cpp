class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tofind=0;
        for(auto it:nums)
            tofind+=it;
        tofind-=x;        
        
        int len=INT_MIN;
        if(tofind<0)
            return -1;
        int curr=0;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            curr+=nums[i];
            while(curr>tofind)
            {
                curr-=nums[j];
                j++;
            }
            if(curr==tofind)
                len=max(len,i-j+1);
        }
        return len==INT_MIN?-1:nums.size()-len;
    }
};