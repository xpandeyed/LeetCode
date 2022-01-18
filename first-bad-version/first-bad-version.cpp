// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int l=1, m, h=n;
        while(l<=h){
            m=(h+l)/2;
            if(isBadVersion(m)){
                if(m==1 || !isBadVersion(m-1)){
                    return m;
                }else{
                    h=m-1;
                }
            }else{
                l=m+1;
            }
            
        }
        return 1;
    }
};