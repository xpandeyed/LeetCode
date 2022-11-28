class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        //first is win and second is loose
        unordered_map<int, pair<int, int>> m;
        for(auto mat: matches){
            if(m.find(mat[0])==m.end()){
                m[mat[0]] = pair<int, int>(1, 0);
            }else{
                m[mat[0]].first++;
            }
            
            if(m.find(mat[1])==m.end()){
                m[mat[1]] = pair<int, int>(0,1);
            }else{
                m[mat[1]].second++;
            }
            
        }
        
        vector<vector<int>> res(2);
        for(auto p: m){
            if(p.second.second==0){
                res[0].push_back(p.first);
            }
            
            if(p.second.second==1){
                res[1].push_back(p.first);
            }
        }
        
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        
        return res;
    }
};