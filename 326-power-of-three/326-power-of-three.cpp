class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1){
            return false;
        }
        return !(1162261467%n);
    }
};