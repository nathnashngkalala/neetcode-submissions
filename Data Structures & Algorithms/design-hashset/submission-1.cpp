class MyHashSet {
public:
    const unsigned int BASE = 10007;
    vector<int> myHashSet;
    int hash(int key) {
        return key % BASE;
    }
    MyHashSet() {
        myHashSet = vector<int>(BASE, 0);
    }
    
    void add(int key) {
        myHashSet[hash(key)] = key;
    }
    
    void remove(int key) {
        myHashSet[hash(key)] = 0;
    }
    
    bool contains(int key) {
        return myHashSet[hash(key)] != 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */