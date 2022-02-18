class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size(), i;
        if(n==k){
            return "0";
        }
        deque<int> q;
        for(i=0; i<n; ++i){
            if(k==0){
                break;
            }
            while(!q.empty() && (q.back()>num[i] && k>0)){
                k--;
                q.pop_back();
            }
            q.push_back(num[i]);
        }
        
        while(i<n){
            q.push_back(num[i]);
            i++;
        }
        
        while(k>0){
            q.pop_back();
            k--;
        }
        
        while(!q.empty() && q.front()=='0'){
            q.pop_front();
        }
        
        string res = "";
        while(!q.empty()){
            res+=q.front();
            q.pop_front();
        }
        
        if(res==""){
            return "0";
        }
        return res;
    }
};