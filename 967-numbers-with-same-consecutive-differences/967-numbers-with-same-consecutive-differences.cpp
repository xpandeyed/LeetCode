class Solution {
public:
    
    int converter(stack<int> s){
        int multiplier=1, res =0;
        while(!s.empty()){
            // cout << s.top();
            res+=(s.top()*multiplier);
            multiplier*=10;
            s.pop();
        }
        // cout << endl;
        return res;
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        int i;
        for(i=1;i<=9;++i){
            stack<stack<int>> nums, temp;
            stack<int> num ;
            num.push(i);
            nums.push(num);
            while(!nums.empty() and nums.top().size()<n){
                num = nums.top();
                nums.pop();
                int l = num.top();
                if(l+k<=9){
                    num.push(l+k);
                    temp.push(num);
                    num.pop();
                }
                if(l-k>=0 and k!=0){
                    num.push(l-k);
                    temp.push(num);
                    num.pop();
                }
                if(nums.empty()){
                    nums = temp;
                    while(!temp.empty()){
                        temp.pop();
                    }
                }
            }
            
            while(!nums.empty()){
                num = nums.top();
                nums.pop();
                if(num.size()!=n) break;
                int number = converter(num);
                res.push_back(number);
            }
        }
        return res;
    }
};