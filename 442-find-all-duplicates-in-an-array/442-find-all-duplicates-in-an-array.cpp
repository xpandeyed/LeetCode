class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size(), i, index;
        vector<int> res;
        for(i=0; i<n; ++i){
            index = nums[i];
            if(index<0){
                index*=-1;
                index--;
                if(nums[index]<0){
                    if(nums[i]>0)res.push_back(nums[i]);
                    else res.push_back(-nums[i]);
                }else{
                    nums[index]*=-1;
                }
            }else{
                if(nums[index-1]>0){
                    nums[index-1]*=-1;
                }else{
                    if(nums[i]>0)res.push_back(nums[i]);
                    else res.push_back(-nums[i]);
                }
            }
        }
        
        return res;
        
    }
};