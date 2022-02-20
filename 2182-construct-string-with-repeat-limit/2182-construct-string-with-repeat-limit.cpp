class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res = "";
        int n=s.size(), i, count=0, resSize=0;
        priority_queue<pair<int, int>> pq;
        map<int, int> m;
        for(i=0; i<n; ++i){
            if(m.find(s[i])==m.end()){
                m[s[i]]=1;
            }else{
                m[s[i]]++;
            }
        }
        
        for(auto x: m){
            pq.push(x);
        }
        
        while(!pq.empty()){
            char c = pq.top().first;
            int freq = pq.top().second;
            pq.pop();
            if(count==repeatLimit && c==res[resSize-1]){
                if(pq.empty()){
                    return res;
                }else{
                    char nextChar = pq.top().first;
                    int nextFreq = pq.top().second;
                    pq.pop();
                    res+=nextChar;
                    nextFreq--;
                    resSize++;
                    count=1;
                    pq.push(pair<int, int>(c, freq));
                    if(nextFreq>0){
                        pq.push(pair<int, int>(nextChar, nextFreq));
                    }
                    
                }
            }else{
                if(resSize!=0 && res[resSize-1]==c){
                    count++;
                }else{
                    count=1;
                }
                res+=c;
                resSize++;
                freq--;
                if(freq>0){
                    pq.push(pair<int, int>(c, freq));
                }
                
            }
            
        }
        
        
        return res;
    }
};