class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size(), i;
        set<int> s;
        for(int i=1;i<=n;++i){
            s.insert(i);
        }
        vector<int> res;
        for(int i=0;i<n;++i){
            if(s.find(nums[i])==s.end()){
                res.push_back(nums[i]);
            }
            s.erase(nums[i]);
        }
        res.push_back(*s.begin());
        return res;
    }
};