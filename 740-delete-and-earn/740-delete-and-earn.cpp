class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> m;
        int ma=nums[0];
        for(auto x: nums){
            if(m.find(x)==m.end()){
                m[x]=1;
            }else{
                m[x]++;
            }
            ma = max(x, ma);
        }
        vector<int> res(ma+1, 0);
        if(m.find(1)!=m.end()){
            res[1]=m[1];
        }
        int n=nums.size(), i;
        for(i=2; i<=ma; ++i){
            if(m.find(i)==m.end()){
                res[i]=res[i-1];
            }else{
                res[i]=max(i*m[i]+res[i-2], res[i-1]);
            }
        }
        
        return res[ma];
        
        
    }
};