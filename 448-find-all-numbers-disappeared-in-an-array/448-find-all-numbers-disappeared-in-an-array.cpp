class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size(), i, index;
        vector<int> res;
        for(i=0; i<n; ++i){
            index = nums[i];
            if(index<0){
                if(nums[-index-1]>0){
                    nums[-index-1]*=-1;
                }
            }else{
                if(nums[index-1]>0){
                    nums[index-1]*=-1;
                }
            }
        }
        
        for(i=0; i<n; ++i){
            if(nums[i]>0){
                res.push_back(i+1);
            }
        }
        
        return res;
    }
};