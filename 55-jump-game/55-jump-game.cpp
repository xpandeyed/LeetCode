class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(), i, temp;
        vector<bool> res(n, false);
        res[n-1]=true;
        for(i=n-2; i>-1; --i){
            temp=nums[i]+i;
            if(temp>=n-1){
                res[i]=true;
                continue;
            }
            while(temp>i){
                if(res[temp]){
                    res[i]=true;
                    break;
                }
                temp--;
            }
            
        }
        return res[0];
    }
};