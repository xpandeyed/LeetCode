class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.end());
        while(k>0){
            int x=q.top();
            q.pop();
            ++x;
            q.push(x);
            k--;
        }
        unsigned long long int res=1, mod=(1e9+7);
        while(!q.empty()){
            res=(res*q.top())%mod;
            q.pop();
        }
        return res;
        
        
    }
};