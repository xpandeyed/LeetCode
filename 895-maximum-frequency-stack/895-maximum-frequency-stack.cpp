class FreqStack {
public:
    
    map<int, int> freq;
    map<int, stack<int>> freqStack;
    
    int maxFreq=INT_MIN;
    
    
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        freqStack[freq[val]].push(val);
        maxFreq=max(freq[val], maxFreq);
    }
    
    int pop() {
        while(freqStack[maxFreq].empty()){
            maxFreq--;
        }
        int temp = freqStack[maxFreq].top();
        freqStack[maxFreq].pop();
        freq[temp]--;
        return temp;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */