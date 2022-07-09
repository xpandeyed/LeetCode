class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size(), i, j;
        multiset<int> s;
        s.insert(nums[0]);
        for(i=1;i<n;++i){
            nums[i]+=(*s.rbegin());
            s.insert(nums[i]);
            if(i-k>-1){
                s.erase(s.find(nums[i-k]));
            }
            // cout << nums[i] << " ";
        }
        return nums[n-1];
    }
};