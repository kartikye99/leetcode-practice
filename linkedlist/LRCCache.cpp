class LRUCache {
public:
    class Node{
        public:
        int key;
        int value;
        Node *next;
        Node *prev;

    Node(int k, int v){
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }

    };
    unordered_map<int, Node*>mp;

    int cap =0;

    Node *head;
    Node *tail;
// making a function for insertion on begining

    void addToFront(Node *node){
        //connect the new node with first existing node
        node->next = head->next; // head ->next is the existing node 

        //prev will point at dummy node

        node->prev = head;
        // first real node points back at new node

        head->next->prev = node;

        //dummy head point at new node
        head->next = node;
    }

    void removenode(Node *node){
        Node *left = node->prev;
        Node *right = node->next;

        left->next = right;
        right->prev = left;

    }

    void moveToFront(Node *node){
        removenode(node);
        addToFront(node);
    }
    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1,-1);

        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node *node = mp[key];
        moveToFront(node);
        return node->value;
    }
    
    void put(int key, int value) {
        //key already exits 

        if(mp.find(key)!=mp.end()){
            Node *node = mp[key];
            node->value = value;

            moveToFront(node);
            return;
        }
        //MP full h - remove LRU node
        if(mp.size()==cap){
            Node * node = tail->prev;
            mp.erase(node->key);

            removenode(node);
            delete node;
        }

        Node *node = new Node(key,value);
        mp[key] = node;
        addToFront(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */