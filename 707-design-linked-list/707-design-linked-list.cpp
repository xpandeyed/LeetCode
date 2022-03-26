class MyLinkedList {
public:
    
    vector<int> ll;
    int n;
    MyLinkedList() {
        n=0;
    }
    
    int get(int index) {
        if(index>=n){
            return -1;
        }
        return ll[index];
    }
    
    void addAtHead(int val) {
        ll.insert(ll.begin(), val);
        n++;
    }
    
    void addAtTail(int val) {
        ll.push_back(val);
        n++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>n){
            return ;
        }
        if(index==n){
            ll.push_back(val);
            n++;
            return ;
        }
        auto it = ll.begin()+index;
        ll.insert(it, val);
        n++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=n){
            return ;
        }
        n--;
        ll.erase(ll.begin()+index);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */