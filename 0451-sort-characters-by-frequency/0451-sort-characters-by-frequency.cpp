class Solution {
public:
    string frequencySort(string s) {
        map<int, int> m;
        for(auto &x: s){
            m[x]++;
        }
        set<pair<int, int>> st;
        for(auto [c, f]: m){
            st.insert(make_pair(f, c));
        }
        
        s = "";
        
        for(auto [f, c]: st){
            for(int i=0;i<f;++i){
                s+=(char)c;
            }
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};