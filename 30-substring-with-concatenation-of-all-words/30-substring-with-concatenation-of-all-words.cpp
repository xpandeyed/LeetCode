class Solution {
public:
    bool check(string s, map<string, int> m, int l){
        int i;
        for(i=0;i+l<=s.size();i+=l){
            string currWord = s.substr(i, l);
            if(m.find(currWord)!=m.end() and m[currWord]>0){
                m[currWord]--;
            }
            else return false;
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = words.size(), l = words[0].size(), totalLen = l*n, i;
        string currSubstr = "" ;
        map<string, int> m;
        for(auto &x: words){
            m[x]++;
        }
        // for(auto [a, b]: m){
        //     cout << a  << " " << b << endl;
        // }
        for(i=0;i+totalLen<=s.size(); ++i){
            if(check(s.substr(i, totalLen), m, l)){
                res.push_back(i);
            }
        }
        return res;
    }
};
//abcd