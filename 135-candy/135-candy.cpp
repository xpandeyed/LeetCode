class Solution {
public:
    int candy(vector<int>& rat) {
       int ans=rat.size();
       vector<int>all(ans,0);
        int n=ans;
        for(int i=1;i<n;i++)
        {
            if(rat[i-1]<rat[i])
                all[i]=all[i-1]+1;
        }
        ans+=all[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(rat[i+1]<rat[i] and all[i+1]>=all[i])
                all[i]=all[i+1]+1;
            ans+=all[i];
        }
        return ans;
    }
};
// 1 1 1
// 1 1 2