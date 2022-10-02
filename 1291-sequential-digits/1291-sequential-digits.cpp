class Solution {
public:
    vector<int> nextGen(vector<int> curr){
        int n=curr.size(), i;
        bool flag = false;
        for(i=0;i<n;++i){
            curr[i]++;
            if(curr[i]==10){
                flag = true;
                break;
            }
        }
        if(!flag) return curr;
        for(i=0;i<n;++i){
            curr[i]=i+1;
        }
        curr.push_back(i+1);
        return curr;
    }
    int numExtractor(vector<int> num){
        int res=0, ten=10, n=num.size();
        for(int i=0;i<n;++i){
            res*=ten;
            res+=num[i];
        }
        return res;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string s = to_string(low);
        vector<int> n;
        int digits = s.size(), i;
        
        n.push_back(s[0]-'0');
        
        if(n[0]+digits-1>9){
            n[0]=1;
            digits++;
        }
        
        //n contains number in vector form
        for(i=1;i<digits;++i){
            n.push_back(n[i-1]+1);
            if(n[i]==10) return res;
        }
        
        int num = numExtractor(n);
        
        do{
            if(num>=low and num<=high){
                res.push_back(num);
            }
            else if(num>high){
                return res;
            }
            n = nextGen(n);
            num = numExtractor(n);
        }while(num<=high);
        
        
        return res;
    }
};
