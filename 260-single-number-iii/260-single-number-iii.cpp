class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int n=nums.size(), i, all=0, s1=0, s2=0;
        for(i=0; i<n; ++i){
            all^=nums[i];
        }
        //cout << "all " << all << endl;
        all&=(-all);
        //cout << "all " << all << endl;
        for(i=0; i<n; ++i){
            if((all&nums[i])==0){
                //cout << "s1 : " << nums[i] << endl;
                s1^=nums[i];
            }else{
                //cout << "S2 : " << nums[i] << endl;
                s2^=nums[i];
            }
        }
        
        vector<int> res(2);
        res[0] = s1;
        res[1] = s2;
        return res;
    }
};