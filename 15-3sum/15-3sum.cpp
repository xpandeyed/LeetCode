class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n=nums.size(), i, target, l, h, sum;
        vector<vector<int>> res;
        
        if(n<3){
            return res;
        }
        
        
        vector<int> temp;
        
        for(i=0; i<n; ++i){
            temp.clear();
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            target = -nums[i];
            l=i+1;
            h=n-1;
            while(l<h){
                sum=nums[l]+nums[h];
                if(sum>target){
                    h--;
                }else if(sum<target){
                    l++;
                }else{
                    if(temp.size()>1 && temp[1]==nums[l]){
                        l++;
                        h--;
                    }else{
                        temp.clear();
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        res.push_back(temp);
                        l++;
                        h--;
                    }
                }
            }
            
        }
        
        return res;
    }
};