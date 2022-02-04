class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum =0, i, n=nums.size(), res=0, curr;
        map<int, int> ind;
        if(n==1){
            return 0;
        }
        
        for(i=0; i<n; ++i){
            if(nums[i]==1){
                sum++;
            }else{
                sum--;
            }
            
            if(sum==0){
                res = max(res, i+1);
            }
            
            if(ind.find(sum)==ind.end()){
                ind[sum]=i;
            }else{
                curr = i-ind[sum];
                res=max(res, curr);
            }
        }
        
        return res;
        
        
    }
};
