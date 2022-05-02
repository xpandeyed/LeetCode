class ListN{
public:
    int key;
    int value;
    ListN *prev;
    ListN *next;
};
class LRUCache {
public:
    map<int, ListN*> m;
    int cap, s;
    ListN *curr, *head, *tail, *p, *n;
    LRUCache(int capacity) {
        cap=capacity;
        s=0;
        curr=NULL;
        head=NULL;
        tail=NULL;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        
        curr = m[key];
        
        if(curr==tail){
            return curr->value;
        }
        
        
        
        p=curr->prev;
        n=curr->next;
        
        if(p)p->next = n;
        if(n)n->prev = p;
        
        curr->next = NULL;
        curr->prev = tail;
        
        if(head==curr){
            head=n;
        }
        
        tail->next = curr;
        tail = curr;
        
        return curr->value;
    }
    
    void put(int key, int value) {
        
        if(m.find(key)!=m.end()){
            m[key]->value = value;
            
                    curr = m[key];
        
        if(curr==tail){
            return ;
        }
        
        
        
        p=curr->prev;
        n=curr->next;
        
        if(p)p->next = n;
        if(n)n->prev = p;
        
        curr->next = NULL;
        curr->prev = tail;
        
        if(head==curr){
            head=n;
        }
        
        tail->next = curr;
        tail = curr;
            return ;
        }
        
        ListN *temp = new ListN;
        
        temp->key = key;
        temp->value = value;
        
        temp->next = NULL;
        temp->prev = tail;
        
        m[key]=temp;
        
        if(!head){
            head=temp;
            tail=temp;
        }else if(head==tail){
            tail=temp;
            head->next = tail;
        }else{
            tail->next = temp;
            tail = temp;
        }
        
        s++;
        
        if(s>cap){
            m.erase(head->key);
            head=head->next;
            head->prev=NULL;
            s--;
        }
        
        
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */