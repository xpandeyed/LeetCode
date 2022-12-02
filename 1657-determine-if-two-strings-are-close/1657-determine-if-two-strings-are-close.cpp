class Solution {
public:
    bool closeStrings(string w1, string w2) {
        int n1 = w1.size(), n2 = w2.size(), i;
        if(n1!=n2) return false;
        
        map<int, int> m1, m2;
        
        for(i=0;i<n1; ++i){
            m1[w1[i]]++;
            m2[w2[i]]++;
        }
        
        n1 = m1.size();
        n2 = m2.size();
        
        if(n1!=n2) return false;
        
        for(auto [c, f]: m1){
            if(m2.find(c)==m2.end()) return false;
            if(m2[c]==f){
                m1.erase(c);
                m2.erase(c);
                continue;
            }
            
            
            for(auto [x, y]: m1){
                if(y==m2[c]){
                    m1[x] = f;
                    m1.erase(c);
                    m2.erase(c);
                }
            }
            
            if(m1.find(c)!=m1.end()) return false;
        }
        
        return true;
        
        
    }
};