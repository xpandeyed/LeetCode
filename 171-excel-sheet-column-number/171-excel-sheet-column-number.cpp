class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long int res = 0, ts=1;
        int n=columnTitle.size();
        int i=n-1;
        while(i>=0){
            res+=((columnTitle[i]-'A'+1)*ts);
            ts*=26;
            i--;
        }
        return res;
    }
};