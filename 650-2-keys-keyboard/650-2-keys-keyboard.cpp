class Solution {
public:
    int minSteps(int n) {
        int chars=1, left=n-1, operations=0, selectedChars=1;
        while(chars<n){
            // cout << chars << " " << left << endl;
            if(left%chars==0){
                operations++;
                selectedChars=chars;
            }
            operations++;
            chars+=selectedChars;
            left-=selectedChars;
        }
        
        return operations;
    }
};