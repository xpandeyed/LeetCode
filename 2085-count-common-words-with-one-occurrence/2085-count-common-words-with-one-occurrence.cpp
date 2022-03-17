class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> m1, m2;
        
        int res=0;
        
        for(auto x: words1){
            
            if(m1.find(x)==m1.end()){
                m1[x]=1;
            }else{
                m1[x]++;
            }
        }
        
        for(auto x: words2){
            if(m2.find(x)==m2.end()){
                m2[x]=1;
            }else{
                m2[x]++;
            }
        }
        
        for(auto x: m1){
            if(x.second==1 and m2[x.first]==1){
                res++;
            }
        }
        
        return res;
    }
};