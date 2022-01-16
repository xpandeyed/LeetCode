class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0, n=digits.size();
        digits[n-1]++;
        carry=digits[n-1]/10;
        digits[n-1]%=10;
        if(carry==0){
            return digits;
        }
        int i=n-2;
        while(carry!=0 && i>=0){
            digits[i]+=carry;
            carry=digits[i]/10;
            digits[i]%=10;
            i--;
        }
        if(carry!=0){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};