class MinStack {
public:
    
    stack<int> s;
    stack<int> aux;
//     MinStack() {
        
//     }
    
    void push(int val) {
        s.push(val);
        if(aux.empty() || aux.top()>=val){
            aux.push(val);
        }
    }
    
    void pop() {
        if(aux.top()==s.top()){
            aux.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return aux.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */