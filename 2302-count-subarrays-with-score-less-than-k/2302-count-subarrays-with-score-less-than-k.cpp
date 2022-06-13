class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long int n=nums.size(), i, res=0, product=nums[0], start=0, ele=1;
        if(product<k) res++;
        for(i=1;i<n;++i){
            if(ele) product/=ele;
            product+=nums[i];
            ele++;
            product*=ele;
            // cout << product <<ele <<endl;
            while(product>=k and start<=i){
                if(!ele){
                    product = 0;
                    break;
                }
                product/=ele;
                product-=nums[start++];
                ele--;
                product*=ele;
            }
            // cout << ele << endl;
            res+=ele;
            
        }
        return res;
        
    }
};