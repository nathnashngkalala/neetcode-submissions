class MyHashMap {
public:
    const int BASE = 10007;
    vector<pair<int,int>> myHashMap;
    int hash(int key) {
        return key % BASE;
    }
    MyHashMap() {
        myHashMap = vector<pair<int,int>>(BASE, {-1, -1});
    }
    
    void put(int key, int value) {
        myHashMap[hash(key)] = {key, value};
    }
    
    int get(int key) {
        if(myHashMap[hash(key)].first == -1) {
            return -1;
        }
        return myHashMap[hash(key)].second;
    }
    
    void remove(int key) {
        myHashMap[hash(key)] = {-1, -1};
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */