class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> s;
        int n=nums.size();
        int currSum=0;
        int count =0;
        for(int i=0; i<n; ++i){
            currSum+=nums[i];
            if(currSum==k){
                count++;
            }
            if(s.find(currSum-k)!=s.end()){
                count+=s[currSum-k];
            }
            if(s.find(currSum)==s.end()){
                s[currSum]=1;
            }else{
                s[currSum]++;
            }
            
        }
        return count;
    }
};