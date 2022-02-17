class Solution {
public:
    void helper(vector<int> nums, int sum, int index, int n, int target, vector<int> temp, vector<vector<int>> &res){
	if(index>=n){
		return ;
	}
	if(nums[index]+sum>target){
		return ;
	}
	helper(nums, sum, index+1, n, target, temp, res);
	sum+=nums[index];
	temp.push_back(nums[index]);
	if(sum==target){
		res.push_back(temp);
	}
	helper(nums, sum, index, n, target, temp, res);

}

vector<vector<int>> rec(vector<int> nums, int target){
	vector<vector<int>> res;
	int n=nums.size();
	vector<int> temp;
	helper(nums, 0, 0, n, target, temp, res);
	return res;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        return rec(candidates, target);
    }
};