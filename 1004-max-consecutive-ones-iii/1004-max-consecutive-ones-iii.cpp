class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res=0, i, n=nums.size(), rem=k, curr=0;
        if(k>=n){
            return n;
        }
        queue<int> q;
        for(i=0;i<n;++i){
            if(nums[i]){
                curr++;
                res=max(res, curr);
                continue;
            }
            if(rem>0){
                rem--;
                curr++;
                q.push(i);
                res=max(res, curr);
                continue;
            }
            if(q.empty()){
                curr=0;
                continue;
            }
            int ind = q.front();
            q.pop();
            curr = i-ind;
            q.push(i);
            res=max(curr, res);
        }
        return res;
        
    }
};

// 0 1 2 3 4