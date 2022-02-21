class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size(), i, j;
        vector<int> res(n, INT_MAX-2000);
        res[n-1]=0;
        for(i=n-2; i>=0; --i){
            for(j=i+1; j<n && j<=i+nums[i]; ++j){
                res[i]=min(res[i], 1+res[j]);
            }
        }
        // for(auto x: res){
        //     cout << x << " ";
        // }
        return res[0];
        
    }
};