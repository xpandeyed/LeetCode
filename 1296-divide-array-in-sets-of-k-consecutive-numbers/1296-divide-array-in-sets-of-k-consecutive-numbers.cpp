class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        map<int, int> f;
        for(auto x: nums) f[x]++;
        for(auto x: nums){
            if(f[x]==0) continue;
            
            int i=0;
            while(i<k){
                if(f[x+i]==0) return false;
                f[x+i]--;
                i++;
            }
        }
        
        return true;
    }
};