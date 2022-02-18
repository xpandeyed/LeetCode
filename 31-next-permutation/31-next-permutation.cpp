class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), i, flag = 0, minSoFar, k=-1, l;
        //best approach is :
        // Step 1: Find the largest index k, such that A[k]<A[k+1]. If not exist, this is the last permutation. (in this    problem just sort the vector and return.)
        // Step 2: Find the largest index l, such that A[l]>A[k].
        // Step 3: Swap A[k] and A[l].
        // Step 4: Reverse A[k+1] to the end.
        
        for(i=0;i<n-1; ++i){
            if(nums[i]<nums[i+1]){
                k=i;
            }
        }
        
        //cout << k << endl;
        if(k==-1){
            sort(nums.begin(), nums.end());
            return ;
        }
        l=0;
        for(i=0; i<n; ++i){
            if(nums[i]>nums[k]){
                l=i;
            }
        }
        
        swap(nums[l], nums[k]);
        l=k+1;
        k=n-1;
        while(l<k){
            swap(nums[l], nums[k]);
            l++;
            k--;
        }
        
    }
};
