class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(), i, j, total=0, sum, count=0, mi=nums[0];
        for(i=0;i<n; ++i){
            total+=nums[i];
            if(nums[i]==0){
                count++;
            }
            if(nums[i]<mi){
                mi=nums[i];
            }
        }
        if(target>total){
            return 0;
        }
        sum = (total+target)/2;
        if((total+target)%2!=0){
            return 0;
        }
        if(sum<-1){
            return 0;
        }
        vector<vector<int>> res(n+1, vector<int>(sum+1, 0));
        for(i=0; i<n+1;++i ){
            for(j=0; j<sum+1; ++j){
                if(j==0){
                    res[i][j]=1;
                    continue;
                }
                if(i==0){
                    res[i][j]=0;
                    continue;
                }
                if(nums[i-1]==0){
                    res[i][j]=res[i-1][j];
                    continue;
                }
                if(nums[i-1]>j){
                    res[i][j]=res[i-1][j];
                }else{
                    res[i][j] = res[i-1][j]+res[i-1][j-nums[i-1]];
                }
            }
        }
        return res[n][sum]*pow(2, count);
    }
};