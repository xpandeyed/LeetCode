class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n=nums.size(), i, l, h, res, curr;
        
        res=nums[0]+nums[1]+nums[2];
        for(i=0; i<n; ++i){
            l=i+1;
            h=n-1;
            while(l<h){
                curr = nums[l]+nums[h]+nums[i];
                if(abs(curr-target)<abs(res-target)){
                    res = curr;
                }
                if(curr<target){
                    l++;
                }
                else if(curr>target){
                    h--;
                }
                else{
                    l++;
                    h--;
                }
                
            }
        }
        
        return res;
    }
};