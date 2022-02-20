class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size(), i;
        if(n==1){
            return nums[0];
        }
        vector<int> f(n, 0), l(n, 0);
        f[0]=nums[0];
        f[1]=nums[0];
        l[1]=nums[1];
        
        for(i=2; i<n-1; ++i){
            f[i]=max(nums[i]+f[i-2], f[i-1]);
        }
        
        for(i=2; i<n; ++i){
            l[i]=max(nums[i]+l[i-2], l[i-1]);
        }
        
        for(auto x: f){
            cout << x << " " ;
        }
        cout << endl;
        
        for(auto y: l){
            cout << y << " " ;
        }
        cout << endl;
        
        return max(f[n-2], l[n-1]);
    }
};