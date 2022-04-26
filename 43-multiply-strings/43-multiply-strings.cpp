class Solution {
public:

    vector<int> add(vector<int> nums, vector<int> curr){
        int n1=nums.size(), n2=curr.size(), i=0, j=0, carry=0, c;
        vector<int> res;
        reverse(nums.begin(), nums.end());
        reverse(curr.begin(), curr.end());
        while(i<n1 and j<n2){
            c=(nums[i]+curr[j]+carry)%10;
            res.push_back(c);
            carry=(nums[i]+curr[j]+carry)/10;
            i++;
            j++;
        }
        while(j<n2){
            c=(curr[j]+carry)%10;
            res.push_back(c);
            carry=(curr[j]+carry)/10;
            j++;
        }
        while(i<n1){
            c=(nums[i]+carry)%10;
            res.push_back(c);
            carry=(nums[i]+carry)/10;
            i++;
        }
        while(carry>0){
            res.push_back(carry%10);
            carry/=10;
        }
        
        reverse(res.begin(), res.end());
        return res;
        
    }
    string multiply(string num1, string num2) {
        int n1=num1.size(), n2=num2.size(), i, j, zeros=0, k, digit, carry, c;
        vector<int> nums;
        for(i=n1-1; i>-1; --i){
            vector<int> curr;
            carry=0;
            digit = (num1[i]-'0');
            for(j=n2-1; j>-1; --j){
                c=digit*(num2[j]-'0')+carry;
                curr.push_back(c%10);
                carry=c/10;
            }
            while(carry>0){
                curr.push_back(carry%10);
                carry/=10;
            }
            reverse(curr.begin(), curr.end());
            k=0;
            while(k<zeros){
                curr.push_back(0);
                k++;
            }
            nums = add(curr, nums);
            zeros++;
        }
        n1=nums.size();
        i=0;
        string res = "";
        bool nonZeroFound = false;
        for(i=0; i<n1; ++i){
            if(nums[i]>0 or nonZeroFound){
                res+=(nums[i]+'0');
                nonZeroFound=true;
            }
        }
        if(!nonZeroFound){
            return "0";
        }
        return res;
    }
};