class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2);
        int l=0, r=numbers.size()-1;
        while(l<r){
            if(numbers[l]+numbers[r]==target){
                res[0]=l+1;
                res[1]=r+1;
                return res;
            }else if(numbers[l]+numbers[r]>target){
                r--;
            }else{
                l++;
            }
        }
        return res;
    }
};