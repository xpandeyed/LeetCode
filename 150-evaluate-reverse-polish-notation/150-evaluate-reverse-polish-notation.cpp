class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size(), i;
        stack<int> s;
        for(i=0; i<n; ++i){
            if(tokens[i]=="+"){
                int sec=s.top();
                s.pop();
                int f=s.top();
                s.pop();
                s.push(f+sec);
                continue;
            }
            if(tokens[i]=="-"){
                int sec=s.top();
                s.pop();
                int f=s.top();
                s.pop();
                s.push(f-sec);
                continue; 
            }
            if(tokens[i]=="*"){
                int sec=s.top();
                s.pop();
                int f=s.top();
                s.pop();
                s.push(f*sec);
                continue;
            }
            if(tokens[i]=="/"){
                int sec=s.top();
                s.pop();
                int f=s.top();
                s.pop();
                s.push(f/sec);
                continue;
            }
            int num = std::stoi(tokens[i]);
            s.push(num);
            
        }
        return s.top();
    }
};