class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res=0, i, n=nums.size(), j=0;
        multiset<int> s;
        for(i=0; i<n; ++i){
            s.insert(nums[i]);
            while(abs(*s.begin()-*s.rbegin())>limit){
                s.erase(s.find(nums[j++]));
                // j++;
            }
            // cout << j << " " << i << endl;
            res=max(res, i-j+1);
        }
        return res;
    }
};