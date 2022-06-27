class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())return false;
        map<int, int> m;
        set<int> temp;
        for(int i=0;i<s.size();++i){
            if(m.find(s[i])!=m.end() and m[s[i]]!=t[i]) return false;
            else if(m.find(s[i])!=m.end()) continue;
            if(temp.find(t[i])!=temp.end()) return false;
            m[s[i]]=t[i];
            temp.insert(t[i]);
               
        }
        return true;
    }
};