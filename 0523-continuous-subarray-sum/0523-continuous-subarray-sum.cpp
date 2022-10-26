class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        m[0]=-1;
        int sum=0, i, n=nums.size();
        for(i=0;i<n;++i){
            sum+=nums[i];
            sum%=k;
            if(m.find(sum)!=m.end()){
                if(i-m[sum]>1) return true;
            }
            else m[sum]=i;
        }
        return false;
    }
};