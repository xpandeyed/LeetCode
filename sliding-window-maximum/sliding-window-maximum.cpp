class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        int n = nums.size();
        q.push_back(0);
        for(int i=1; i<k-1; ++i){
            while(!q.empty() && nums[q.back()]<=nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        for(int i=k-1; i<n; ++i){
            while(!q.empty() && nums[q.back()]<nums[i]){
                q.pop_back();
            }
            while(!q.empty() && q.front()<(i-k+1)){
                q.pop_front();
            }
            q.push_back(i);
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};