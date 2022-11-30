class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> occ;
        set<int> s;
        for(auto x: arr){
            occ[x]++;
        }
        for(auto [x, y]: occ){
            if(s.find(y)==s.end()){
                s.insert(y);
            }else return false;
        }
        
        return true;
    }
};