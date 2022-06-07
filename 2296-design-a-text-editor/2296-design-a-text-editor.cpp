class TextEditor {
public:
    stack<char> left;
    stack<char> right;
    
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(char c: text){
            left.push(c);
        }
    }
    
    int deleteText(int k) {
        int res=0;
        while(!left.empty() and k>0){
            k--;
            res++;
            left.pop();
        }
        return res;
    }
    
    string cursorLeft(int k) {
        while(!left.empty() and k>0){
            k--;
            right.push(left.top());
            left.pop();
        }
        return cursorShift();
    }
    
    string cursorRight(int k) {
        while(!right.empty() and k>0){
            k--;
            left.push(right.top());
            right.pop();
        }
        return cursorShift();
    }
    
    string cursorShift(){
        int k=10;
        string res="";
        while(k>0 and !left.empty()){
            res+=left.top();
            left.pop();
            k--;
        }
        reverse(res.begin(), res.end());
        for(char &c: res){
            left.push(c);
        }
        return res;
    }
    
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */