class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size(), i;
        map<int, int> m;
        vector<int> res(2);
        for(i=0; i<n; ++i){
            if(m.find(target-nums[i])==m.end()){
                m[nums[i]]=i;
            }else{
                res[0]=m[target-nums[i]];
                res[1]=i;
                return res;
            }
        }
        
        return res;
    }
};