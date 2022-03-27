class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        vector<pair<int, int>> sols;
        int i, n=mat.size(), currSol;
        for(i=0; i<n; ++i){
            currSol = 0;
            for(auto x: mat[i]){
                if(x){
                    currSol++;
                }
            }
            sols.push_back(pair<int, int>(currSol, i));
        }
        
        sort(sols.begin(), sols.end());
        
        for(i=0; i<k; ++i){
            res.push_back(sols[i].second);
        }
        
        return res;
    }
};