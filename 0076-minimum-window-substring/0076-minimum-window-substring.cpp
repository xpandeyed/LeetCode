class Solution {
public:
    string minWindow(string s, string t) {
        map<int, int> fr, cf;
        pair<int,int> p;
        p.first=-1000;
        p.second=10000000;
        for(auto ch: t){
            if(fr.find(ch)==fr.end()){
                fr[ch]=1;
            }else{
                fr[ch]++;
            }
        }
        int n=s.size(), i;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(i=0; i<n; ++i){
            if(fr.find(s[i])==fr.end()){
                continue;
            }
            pq.push(i);
            if(cf.find(s[i])==cf.end()){
                cf[s[i]]=1;
            }else{
                cf[s[i]]++;
            }
            // cout <<i << endl;
            while(cf[s[pq.top()]]>fr[s[pq.top()]]){
                // cout << "  deleting: " << s[pq.top()] << endl;
                cf[s[pq.top()]]--;
                pq.pop();
            }
            bool isValid=true;
            for(auto x: fr){
                if(cf.find(x.first)==cf.end() or cf[x.first]<x.second){
                    isValid=false;
                    break;
                }
            }
            if(isValid and (i-pq.top())<(p.second-p.first)){
                p.second=i;
                p.first=pq.top();
            }
            
            
        }
        
        if(p.first>-1 and p.second<n){
            return s.substr(p.first, p.second-p.first+1);
        }
        
        return "";
        
        
    }
};