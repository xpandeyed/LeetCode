class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        

        
        vector<long long int> temp(2, 922337203685477580);
        int n=nums.size(), i;
        
        if(n==0){
            return res;
        }
        
        for(i=0; i<n; ++i){
            if(temp[0]==922337203685477580){
                temp[0]=nums[i];
                continue;
            }
            
            if(temp[0]!=922337203685477580 && temp[1]==922337203685477580){
                if(nums[i]==temp[0]+1){
                    temp[1]=nums[i];
                }else{
                    res.push_back(to_string(temp[0]));
                    temp[0]=nums[i];
                    temp[1]=922337203685477580;
                }
                continue;
            }
            
            if(temp[0]!=922337203685477580 && temp[1]!=922337203685477580){
                if(temp[1]+1==nums[i]){
                    temp[1]=nums[i];
                }else{
                    string s = to_string(temp[0]);
                    s+=("->");
                    s+=to_string(temp[1]);
                    res.push_back(s);
                    temp[0]=nums[i];
                    temp[1]=922337203685477580;
                }
            }
        }
        
        if(temp[0]!=922337203685477580 && temp[1]==922337203685477580){
            res.push_back(to_string(temp[0]));
        }else{
            string s = to_string(temp[0]);
            s+=("->");
            s+= to_string(temp[1]);
            res.push_back(s);
        }
        
        return res;
    }
};