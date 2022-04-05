class Solution {
public:
    int numRabbits(vector<int>& nums) {
        int res=0, i, n=nums.size();
        unordered_map<int, int> freq;
        for(i=0; i<n; ++i){
            if(nums[i]==0){
                res++;
                continue;
            }
            
            if(freq.find(nums[i])==freq.end()){
                freq[nums[i]]=1;
            }else if(freq[nums[i]]==(nums[i]+1)){
                res+=(nums[i]+1);
                freq[nums[i]]=1;
            }else{
                freq[nums[i]]++;
            }
            
        }
            for(auto x: freq){
                res+=x.first;
            }
            
            res+=freq.size();
            
            return res;
    }
};