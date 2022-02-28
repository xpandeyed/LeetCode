class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res= 0;
        int bits=32;
        while(--bits){
            if(n&1){
                res|=1;
            }
            res<<=1;
            n>>=1;
        }
        if(n&1){
            res|=1;
        }
        
        return res;
        
    }
};