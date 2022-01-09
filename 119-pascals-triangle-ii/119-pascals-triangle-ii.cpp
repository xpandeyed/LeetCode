class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(1, 1);
        int n=1;
        while(n<=rowIndex){
            int prevOld=1, curr;
            for(int i=1; i<n; ++i){
                curr = res[i];
                res[i]+=prevOld;
                prevOld = curr;
            }
            res.push_back(1);
            n++;
        }
        return res;
    }
};