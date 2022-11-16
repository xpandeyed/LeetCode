/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        long long int l=1, h=n;
        while(true){
            long long int temp = guess((l+h)/2);
            if(temp==0) return (l+h)/2;
            else if(temp==1) l=((l+h)/2+1);
            else h=((l+h)/2-1);
            
        }
        
        return n;
        
    }
};