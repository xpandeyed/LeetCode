class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size(), i, res = 0, e, c;
        map<int, int> m;
        for(i=0; i<n; ++i){
            if(m.find(nums[i])==m.end()){
                m[nums[i]]=1;
            }else{
                m[nums[i]]++;
            }
        }
        set<int> s;
        for(auto x: m){
            e=x.first;
            c=k-e;
            if(e==c and s.find(e)==s.end()){
                res+=(m[e]/2);
                s.insert(e);
                continue;
            }
            
            if(m.find(c)!=m.end() and (s.find(c)==s.end() and s.find(e)==s.end())){
                // cout << c << " " << e << endl;
                res+=min(m[e], m[c]);
                s.insert(e);
                s.insert(c);
            }
        }
        return res;
    }
};