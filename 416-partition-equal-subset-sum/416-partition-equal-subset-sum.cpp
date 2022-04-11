class Solution {
public:
    bool rec(vector<int> &nums, int left, int right, int i, int n){
        if(i==n-1){
            if(abs(left-right)==nums[i]){
                return true;
            }else{
                return false;
            }
        }
        
        return rec(nums, left+nums[i], right, i+1, n) or rec(nums, left, right+nums[i], i+1, n);
    }
    
    bool isSubset(vector<int> &nums, int sum, int i, int n, int res){
        if(sum==res){
            return true;
        }
        if(i>=n){
            return false;
        }
        if(sum+nums[i]<=res){
            return isSubset(nums, sum+nums[i], i+1, n, res) or isSubset(nums, sum, i+1, n, res);
        }
        return isSubset(nums, sum, i+1,n, res);
        
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x: nums){
            sum+=x;
        }
        if(sum%2){
            return false;
        }
        
        // return rec(nums, 0, 0, 0, nums.size());
        
        // return isSubset(nums, 0, 0, nums.size(), sum/2);
        return dynamic(nums);
        
    }
    
    private:
    bool dynamic(vector<int> &nums){
        int sum=0, n=0, i, j;
        for(int x: nums){
            n++;
            sum+=x;
        }
        if(sum%2){
            return false;
        }
        
        vector<vector<bool>> results(n+1, vector<bool>(sum/2+1, false));
        for(i=0;i<=n; ++i){
            for(j=0; j<=sum/2; ++j){
                if(j==0){
                    results[i][j]=true;
                    continue;
                }
                if(i==0){
                    continue;
                }
                if(nums[i-1]>j){
                    if(i>0)results[i][j]=results[i-1][j];
                }else{
                    results[i][j]=results[i-1][j] or results[i-1][j-nums[i-1]];
                }
                
                
                
            }
        }
            return results[n-1][sum/2];
    }
};