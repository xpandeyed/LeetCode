class Solution {
public:
    
    bool areAnagram(map<int, int> p, map<int, int> s){
        for(auto x: p){
            
            // cout << x.first << " " << x.second << endl;
            
            if(s.find(x.first)==s.end()){
                // cout << "    key not found" << endl;
                return false;
            }else if(s[x.first]!=p[x.first]){
                // cout << "    vals not equal" << s[x.first] << " " << p[x.first] << endl;
                return false;
            }
            // else{
            //     cout << "    vals equal" << s[x.first] << " " << p[x.first] << endl;
            // }
        }
        
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(), m=p.size(), i, j;
        
        map<int, int> mp, ms;
        for(i=0; i<m; ++i){
            if(mp.find(p[i])==mp.end()){
                mp[p[i]]=1;
            }else{
                mp[p[i]]++;
            }
        }
        
        vector<int> res;
        
        for(i=0; i<n; ++i){
            
            if(i-m>-1 && ms.find(s[i-m])!=ms.end()){
                ms[s[i-m]]--;
            }
            
            if(mp.find(s[i])==mp.end()){
                continue;
            }
            
            if(ms.find(s[i])==ms.end()){
                ms[s[i]]=1;
            }else{
                ms[s[i]]++;
            }
            
            if(areAnagram(mp, ms)){
                res.push_back(i-m+1);
            }
        }
        
            return res;
    }
};