class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        int curr, carry=0, i, n=num.size();
        num[0]+=k;
        carry=num[0]/10;
        num[0]%=10;
        for(i=1; i<n; ++i){
            curr = num[i]+carry;
            num[i]=curr%10;
            carry=curr/10;
        }
        while(carry){
            num.push_back(carry%10);
            carry/=10;
        }
        reverse(num.begin(), num.end());
        return num;
    }
};