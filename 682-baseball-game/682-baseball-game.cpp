class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res=0, i, n=ops.size();
        stack<int> s;
        for(i=0; i<n; ++i){
            if(ops[i]=="+"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.push(a);
                s.push(a+b);
            }else if(ops[i]=="D"){
                s.push(2*s.top());
            }else if(ops[i]=="C"){
                s.pop();
            }else{
                s.push(std::stoi(ops[i]));
            }
        }
        while(!s.empty()){
            res+=s.top();
            s.pop();
        }
        return res;
    }
};