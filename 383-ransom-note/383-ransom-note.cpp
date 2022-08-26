class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int rnsize = ransomNote.size(), msize=magazine.size();
        if(rnsize>msize){
            return false;
        }
        vector<int> temp1(256, 0), temp2(256, 0);
        
        for(int i=0; i<rnsize; ++i){
            temp1[ransomNote[i]]++;
        }
        
        for(int i=0; i<msize; ++i){
            temp2[magazine[i]]++;
        }
        
        for(int i=0; i<256; ++i){
            if(temp2[i]<temp1[i]){
                return false;
            }
        }
        
        return true;
    }
};