class Solution {
public:
    string reverse(string s){
        int l=0, h=s.size()-1;
        while(l<h){
            swap(s[l], s[h]);
            l++;
            h--;
        }
        
        return s;
    }
    
    string minRemoveToMakeValid(string s) {
        int n=s.size(), i, o=0, c=0;
        string res="";
        stack<int> st;
        for(i=0; i<n; ++i){
            // cout << s[i] << " " << o << " " << c << endl;
            
            if(s[i]==')'){
                
                if(o>c){
                    st.push(')');
                    c++;
                    
                }
                
            }else{
                if(s[i]=='('){
                    o++;
                }
                st.push(s[i]);
            }
        }
        
        c=0;
        o=0;
        while(!st.empty()){
            
            if(st.top()!='(' ){
                
                if(st.top()==')'){
                    c++;
                }
                
                
                res+=(st.top());
                st.pop();
                continue;
            }
            
            if(o<c){
                o++;
                res+=(st.top());
                st.pop();
            }else{
                st.pop();
            }
        }
        
        s = reverse(res);
        return s;
        
    }
};