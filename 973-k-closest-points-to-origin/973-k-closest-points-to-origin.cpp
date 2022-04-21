class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(k==points.size()){
            return points;
        }
        map<int, vector<pair<int, int>>> m;
        for(auto x: points){
            m[(x[0]*x[0])+(x[1]*x[1])].push_back(pair<int, int>(x[0], x[1]));
        }
        int i=0;
        vector<vector<int>> res;
        auto it = m.begin();
        while(i<k){
            int n=(*it).second.size(), z;
            for(z=0; z<n and i<k; ++z){
                vector<int> temp = {(*it).second[z].first, (*it).second[z].second};
                res.push_back(temp);
                i++;
            }
            it++;
        }
        return res;
    }
};