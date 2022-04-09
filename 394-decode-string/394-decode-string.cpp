class Solution {
public:
    
    int converter(deque<int> q){
        int n=q.size(), tens=1, res=0;
        while(!q.empty()){
            res+=(q.front()*tens);
            q.pop_front();
            tens*=10;
        }
        return res;
    }
    
    string sol(string s){
        stack<string> keys;
        int n=s.size(), i;
        string curr, temp;
        for(i=n-1; i>-1; --i){
            // cout << s[i] << endl;
            if(s[i]==']'){
                keys.push("]");
            }else if(s[i]=='['){
                keys.push("[");
            }else if(s[i]>='a' and s[i]<='z'){
                temp="";
                temp+=s[i];
                keys.push(temp);
            }else{
                deque<int> q;
                while(i>-1 and (s[i]>='0' and s[i]<='9')){
                    q.push_back(s[i]-'0');
                    i--;
                }
                i++;
                int num = converter(q);
                curr="";
                while(!keys.empty() and keys.top()!="]"){
                    if(keys.top()!="[" and keys.top()!="]"){
                        curr+=keys.top();
                    }
                    keys.pop();
                }
                keys.pop();
                string multi="";
                while(num>0){
                    multi+=curr;
                    num--;
                }
                // cout << multi << endl;
                keys.push(multi);
            }
            
            
        }
        string res="";
        // cout << "f" << endl;
        while(!keys.empty()){
            if(keys.top()!="]" and keys.top()!="["){
            res+=keys.top();
                
            }
            keys.pop();
        }
        return res;
    }
    
    string decodeString(string s) {
        // deque<int> q;
        // q.push_back(2);
        // q.push_back(3);
        // cout <<converter(q);
        return sol(s);
    }
};