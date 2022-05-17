class Solution {
public:
    int arraySign(vector<int>& nums) {
        int p=0, n=0, z=0;
        for(int x: nums){
            if(!x){
                return 0;
            }
            if(x>0){
                p++;
            }
            if(x<0){
                n++;
            }
        }
        if(!(n%2)){
            return 1;
        }
        return -1;
    }
};