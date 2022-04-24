class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size(), i, j, res=0, l, h, m, s;
        sort(nums.begin(), nums.end());
        for(i=0; i<=n-3; ++i){
            for(j=i+1; j<=n-2; ++j){
                l=j+1;
                h=n-1;
                s=nums[i]+nums[j];
                while(l<=h){
                    m=(l+h)/2;
                    if((m<n-1 and (nums[m]<s and nums[m+1]>=s)) or m==n-1){
                        break;
                    }else if(nums[m]>=s){
                        h=m-1;
                    }else{
                        l=m+1;
                    }
                }
                if(nums[m]<s){
                    res+=(m-j);
                }
            }
        }
        return res;
    }
};