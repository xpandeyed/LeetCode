class MyCircularQueue {
public:
    
    int *arr, i, n, front, rear, k;
    
    MyCircularQueue(int s) {
        arr = new int[s];
        k=s;
        i=0;
        n=0;
        front=-1;
        rear=-1;
    }
    
    bool enQueue(int value) {
        if(n==k){
            return false;
        }
        if(n==0){
            front=0;
            rear=0;
        }else if(rear==k-1){
            rear=0;
        }else{
            rear++;
        }
        arr[rear]=value;
        n++;
        return true;
    }
    
    bool deQueue() {
        if(n==0){
            return false;
        }
        if(n==1){
            n--;
            return true;
        }
        
        if(front==k-1){
            front=0;
            n--;
            return true;
        }
        
        front++;
        n--;
        return true;
        
    }
    
    int Front() {
        if(n==0){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(n==0){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        return n==0;
    }
    
    bool isFull() {
        return n==k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */