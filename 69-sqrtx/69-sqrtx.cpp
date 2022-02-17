class Solution {
public:
    int mySqrt(int x) {
        long long int y=x/2;
        while(!((y+1)*(y+1)>x && y*y<x)){
            if(y*y==x){
                return y;
            }
            if(y*y<x){
                y++;
            }else{
                y=y/2;
            }
        }
        return y;
    }
};