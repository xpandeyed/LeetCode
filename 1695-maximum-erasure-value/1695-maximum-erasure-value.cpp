class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=nums[0], res=sum, start=0, i, n=nums.size();
        map<int, int> m;
        m[nums[0]]=0;
        //map stores last occurrence of a number
        for(i=1;i<n;++i){
            // cout << nums[i];
            if(m.find(nums[i])==m.end()){
                sum+=nums[i];
                // cout << " not Found. Sum: " << sum << endl;
                m[nums[i]]=i;
                res=max(res, sum);
                continue;
            }
            
            int ind = m[nums[i]];
            // cout << " found at index: " << ind ;
            while(ind>=start){
                // cout << " Subtracting: " << nums[start] << " " ;
                sum-=nums[start++];
            }
            sum+=nums[i];
            // cout << "Start: " << start << " Sum: " << sum << endl;
            res=max(res, sum);
            m[nums[i]]=i;
        }
        return res;
    }
};