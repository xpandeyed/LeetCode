class Solution {
public:
    
    unordered_set<string> bank;
    string f;
    int res = INT_MAX;
    
    
    int solve(string s){
        queue<string> q;
        q.push(s);
        int mutations = 0;
        while(q.size()>0){
            int n=q.size();
            for(int k=0;k<n;++k){
                string curr=q.front(), temp;
                q.pop();
                if(curr==f) return mutations;
                for(int i=0;i<8;++i){
                    temp = curr;
                    if(temp[i]=='A'){
                        temp[i]='C';
                        if(bank.find(temp)!=bank.end()){
                            q.push(temp);
                            bank.erase(temp);
                        }
                        temp[i]='G';
                        if(bank.find(temp)!=bank.end()){
                            q.push(temp);
                            bank.erase(temp);
                        }
                        temp[i]='T';
                        if(bank.find(temp)!=bank.end()){
                            q.push(temp);
                            bank.erase(temp);
                        }
                    }
                    if(temp[i]=='C'){
                        temp = curr;
                        temp[i]='A';
                        if(bank.find(temp)!=bank.end()){
                            q.push(temp);
                            bank.erase(temp);
                        }
                        temp = curr;
                        temp[i]='G';
                        if(bank.find(temp)!=bank.end()){
                            q.push(temp);
                            bank.erase(temp);
                        }
                        temp = curr;
                        temp[i]='T';
                        if(bank.find(temp)!=bank.end()){
                            q.push(temp);
                            bank.erase(temp);
                        }
                    }
                    if(temp[i]=='G'){
                        temp = curr;
                        temp[i]='C';
                        if(bank.find(temp)!=bank.end()){
                            q.push(temp);
                            bank.erase(temp);
                        }
                        temp = curr;
                        temp[i]='A';
                        if(bank.find(temp)!=bank.end()){
                            q.push(temp);
                            bank.erase(temp);
                        }
                        temp = curr;
                        temp[i]='T';
                        if(bank.find(temp)!=bank.end()){
                            q.push(temp);
                            bank.erase(temp);
                        }
                    }
                    if(temp[i]=='T'){
                        temp = curr;
                        temp[i]='C';
                        if(bank.find(temp)!=bank.end()){
                            q.push(temp);
                            bank.erase(temp);
                        }
                        temp = curr;
                        temp[i]='G';
                        if(bank.find(temp)!=bank.end()){
                            q.push(temp);
                            bank.erase(temp);
                        }
                        temp = curr;
                        temp[i]='A';
                        if(bank.find(temp)!=bank.end()){
                            q.push(temp);
                            bank.erase(temp);
                        }
                    }
                }
            }
            mutations++;
        }
        return -1;
    }
    
    int minMutation(string start, string end, vector<string>& b) {
        for(auto &x: b){
            bank.insert(x);
        }
        f=end;
        return solve(start);
        
    }
};