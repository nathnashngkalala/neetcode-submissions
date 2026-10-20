class MyStack {
public:
    /*
        okay so I guess we can do lienar lol, I will just
        do a one queue implementation
        [1]
        [1,2]
        [2,1]
        [3,2,1]
    */
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        queue<int> temp;
        temp.push(x);
        while(q1.size() > 0) {
            temp.push(q1.front());
            q1.pop();
        }
        q1 = temp;
    }
    
    int pop() {
        if(empty()) {
            return -1;
        }
        int res = q1.front();
        q1.pop();
        return res;
    }
    
    int top() {
        if(empty()) {
            return -1;
        }
        return q1.front();
    }
    
    bool empty() {
        return q1.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */