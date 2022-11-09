class StockSpanner {
public:
    
    stack<pair<int, int>> s;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 0;
        while(!s.empty() and s.top().first<=price){
            count+=(s.top().second);
            s.pop();
        }
        count++;
        s.push(make_pair(price, count));
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */