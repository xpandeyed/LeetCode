class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1, 0);
        int i;
        for(i=1; i<=n; ++i){
            if(i%2==0){
                bits[i] = bits[i/2];
            }else{
                bits[i] = bits[i/2]+1;
            }
        }
        
        return bits;
    }
};