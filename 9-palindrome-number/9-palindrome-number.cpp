class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long int y =0, temp =x;
        while(x>0){
            y*=10;
            y+=(x%10);
            x/=10;
        }
        cout << y << " " ;
        return temp==y;
    }
};