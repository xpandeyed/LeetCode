class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> tempRes(2*n, -1);
        nums.insert(nums.end(), nums.begin(), nums.end());
        stack<int> s;
        for(int i=(2*n)-1; i>=0; i--){
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }
            if(!s.empty()){
                tempRes[i] = s.top();
            }
            s.push(nums[i]);
            
        }
        vector<int> res;
        res.insert(res.begin(), tempRes.begin(), tempRes.begin()+n);
        return res;
    }
};