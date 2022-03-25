class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long long int n=(long long int)nums.size(), i, j, h, l, k=0;
        vector<int> temp(4);
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(i=0; i<n; ++i){
            for(j=i+1; j<n; ++j){
                l=j+1;
                h=n-1;
                while(l<h){
                    if(l==i or l==j){
                        l++;
                        continue;
                    }
                    if(h==j or j==h){
                        h--;
                        continue;
                    }
                    if(((long long int)nums[i]+(long long int)nums[j]+(long long int)nums[l]+(long long int)nums[h])==(long long int)target){
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[l];
                        temp[3]=nums[h];
                        l++;
                        h--;
                        if(find(res.begin(), res.end(), temp)==res.end()){
                            res.push_back(temp);
                        }
                    }
                    if(((long long int)nums[i]+(long long int)nums[j]+(long long int)nums[l]+(long long int)nums[h])>(long long int)target){
                        h--;
                        continue;
                    }
                    if(((long long int)nums[i]+(long long int)nums[j]+(long long int)nums[l]+(long long int)nums[h])<(long long int)target){
                        l++;
                        continue;
                    }
                    
                }
            }
        }
        
        return res;
    }
};