class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0, i, n=nums.size();
        for(i=0; i<n;++i){
            if(nums[i]%2==0)
                sum+=nums[i];
        }
        vector<int> res;
        n=queries.size();
        for(i=0;i<n;++i){
            if(nums[queries[i][1]]%2==0){
                sum-=nums[queries[i][1]];
                nums[queries[i][1]]+=queries[i][0];
                if(nums[queries[i][1]]%2==0)
                    sum+=nums[queries[i][1]];
                res.push_back(sum);
                continue;
            }
            nums[queries[i][1]]+=queries[i][0];
            if(nums[queries[i][1]]%2==0)
                sum+=nums[queries[i][1]];
            res.push_back(sum);
            
        }
        return res;
    }
};