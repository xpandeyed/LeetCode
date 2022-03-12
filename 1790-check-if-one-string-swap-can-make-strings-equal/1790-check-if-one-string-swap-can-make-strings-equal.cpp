class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        bool res = true;
        int n=s1.size(), i, i1=-1, i2=-1;
        
        for(i=0; i<n; ++i){
            if(s1[i]==s2[i]){
                continue;
            }
            
            if(i1==-1){
                i1=i;
            }
            else if(i2==-1){
                i2=i;
            }
            else{
                return false;
            }
        }
        
        if(i1==-1 and i2==-1){
            return true;
        }
        
        if(i1!=-1 and i2==-1){
            return false;
        }
        
        swap(s1[i1], s1[i2]);
        
        return s1==s2;
        
    }
};