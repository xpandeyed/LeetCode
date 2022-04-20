class Solution {
public:
    vector<int> temp;
    Solution(vector<int> nums) {
        temp = nums;
    }
    
    vector<int> reset() {
        return temp;
    }
    
    vector<int> shuffle() {
        vector<int> res(temp);
        int n=temp.size(), i;
        for(i=0; i<n; ++i){
            int pos = rand()%(n-i);
            swap(res[i+pos], res[i]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */