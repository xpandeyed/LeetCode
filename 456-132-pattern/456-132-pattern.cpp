class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size(), i, s3=INT_MIN;
        if(n<3){
            return false;
        }
        stack<int> s;
        for(i=n-1; i>-1; --i){
            if(nums[i]<s3)return true;
            while(!s.empty() and s.top()<nums[i]){
                s3=s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};