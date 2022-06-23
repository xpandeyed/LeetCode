class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        map<int, set<int>> m;
        for(auto x: mappings){
            m[x[0]].insert(x[1]);
        }
        // for(auto x: m){
        //     cout << (char)x.first << " ";
        //     for(auto y: x.second){
        //         cout << (char)y << " ";
        //     }
        //     cout << endl;
        // }
        int i, n1=s.size(), n2=sub.size();
        for(i=0;i<=n1-n2;++i){
            int tempI=i, j=0;
            while((j<n2 and tempI<n1) and (s[tempI]==sub[j] or !(m.find(sub[j])==m.end() or m[sub[j]].find(s[tempI])==m[sub[j]].end()))){
                // cout << tempI << " " << j << endl;
                tempI++;
                j++;
            }
            if(j==n2) return true;

        }
        return false;
    }
};

// "lllllllllllllllllllllllrlllllllllllllllllllllllllllllllll"
// "lllllllllllllllllllllllllllllllll"
// []