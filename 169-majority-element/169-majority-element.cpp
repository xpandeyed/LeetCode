class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =1;
        int curr = nums[0];
        int n = nums.size();
        int i=0;
        for(int i=1; i<n; ++i){
            if(nums[i]==curr){
                count++;
                continue;
            }
            count--;
            if(count==0){
                curr=nums[i];
                count=1;
            }
            
        }
        return curr;
    }
};