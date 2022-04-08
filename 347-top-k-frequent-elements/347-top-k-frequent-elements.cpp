class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(int x: nums){
            if(m.find(x)==m.end()){
                m[x]=1;
            }else{
                m[x]++;
            }
        }
        map<int, vector<int>> n;
        for(auto x: m){
            n[x.second].push_back(x.first);
        }
        vector<int> res;
        auto it = n.rbegin();
        int i=0;
        while(i<k){
            vector<int> temp = (*it).second;
            for(int j=0; j<temp.size() and i<k ; ++j){
                res.push_back(temp[j]);
                i++;
            }
            it++;
        }
        return res;
    }
};