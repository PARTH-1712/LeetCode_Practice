class LRUCache {
public:
    LRUCache(int _capacity) :
        capacity(_capacity)
    {
        key_node_map.reserve(capacity);
        node_key_map.reserve(capacity);
        head.data = end.data = 0;
        head.prev = end.next = nullptr;
        head.next = &end;
        end.prev = &head;
        length = 0;
    }
    
    int get(int key) {
        if (key_node_map.find(key) == key_node_map.end())
            return -1;
        
        // node exists, move it to the front

        Node* curr = key_node_map[key];
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        Node* tmp = head.next;
        curr->prev = &head;
        curr->next = tmp;
        head.next = curr;
        tmp->prev = curr;

        return curr->data;
    }
    
    void put(int key, int value) { 
        if (get(key) != -1) {
            key_node_map[key]->data = value;
            return; 
        }

        // if node not found, add node

        if (length == capacity) {  // evict node before `end` if cache is full
            Node* evict_node = end.prev;
            evict_node->prev->next = &end;
            end.prev = evict_node->prev;
            int evict_key = node_key_map[evict_node];
            key_node_map.erase(evict_key);
            node_key_map.erase(evict_node);
             delete evict_node;
        } else {
            length++;
        }

        // add new node to the front

        Node* tmp = new Node;
        tmp->data = value;
        tmp->next = head.next;
        tmp->prev = &head;
        head.next->prev = tmp;
        head.next = tmp;
        key_node_map[key] = tmp;
        node_key_map[tmp] = key;
    }

private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };

    Node head;
    Node end;
    int capacity;
    int length;
    unordered_map<int, Node*> key_node_map;
    unordered_map<Node*, int> node_key_map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */