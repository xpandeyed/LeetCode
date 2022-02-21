class Solution {
public:
    int findBegin(vector<int> nums, int t){
        int n=nums.size(), l, h, m;
        l=0;
        h=n-1;
        while(l<=h){
            m = (l+h);
            if(nums[m]==t && (m==0 || nums[m-1]!=t)){
                return m;
            }else if(nums[m]<t){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        
        return -1;
    }
    
    int findLast(vector<int> nums, int t){
        int n=nums.size(), l, h, m;
        l=0;
        h=n-1;
        while(l<=h){
            m = (l+h);
            if(nums[m]==t && (m==n-1 || nums[m+1]!=t)){
                return m;
            }else if(nums[m]>t){
                h=m-1;
            }else{
                l=m+1;
            }
        }
        
        return -1;        
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);
        res[0]=findBegin(nums, target);
        res[1]=findLast(nums, target);
        return res;
        
    }
};