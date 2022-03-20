class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        vector<int> freq(7, 0), topFreq(7, 0), bottomFreq(7, 0);
        
        int n=tops.size(), i, num=-1, res=INT_MAX;
        
        for(i=0; i<n; ++i){
            
            if(tops[i]==bottoms[i]){
                if(num!=-1 and (tops[i]!=num or bottoms[i]!=num)){
                    return -1;
                }
                num=tops[i];
                freq[tops[i]]++;
            }else{
                freq[tops[i]]++;
                freq[bottoms[i]]++;
            }
            
            topFreq[tops[i]]++;
            bottomFreq[bottoms[i]]++;
        }
        
        for(i=1; i<=6; ++i){
            if(freq[i]==n){
                if(topFreq[i]+bottomFreq[i]>n){
                    int noFlips = (topFreq[i]+bottomFreq[i]-n);
                    
                    // cout << noFlips << endl;
                    
                    topFreq[i]-=noFlips;
                    bottomFreq[i]-=noFlips;
                    
                    res = min(res, min(topFreq[i], bottomFreq[i]));
                    
                }else{
                    res = min(res, min(topFreq[i], bottomFreq[i]));
                }
            }
        }
        
        
        if(res==INT_MAX){
            return -1;
        }
        
        return res;
        
        
        
        
    }
};