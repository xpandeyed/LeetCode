class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> res;
        if(num%3==0){
            res.push_back(num/3-1);
            res.push_back(num/3);
            res.push_back(num/3+1);
        }
        return res;
    }
};