class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int x: nums){
            s.insert(x);
        }
        
        
        int res=0, curr, t;
        
        for(int x: s){
            if(s.find(x-1)==s.end()){
                curr=1;
                t=x;
                while(s.find(t+1)!=s.end()){
                    t++;
                    curr++;
                }
                res=max(res, curr);
            }
        }
        
        return res;
    }
};