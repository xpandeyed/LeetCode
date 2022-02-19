class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size(), i;
        set<int> s;
        for(i=0 ; i<n; ++i){
            if(nums[i]%2==0){
                s.insert(nums[i]);
            }else{
                s.insert(nums[i]*2);
            }
        }
        
        int diff = *s.rbegin() - *s.begin();
        while((*s.rbegin())%2==0){
            i = *s.rbegin();
            s.erase(i);
            s.insert(i/2);
            diff = min(*s.rbegin() - *s.begin(), diff);
        }

        
        return diff;
    }
};