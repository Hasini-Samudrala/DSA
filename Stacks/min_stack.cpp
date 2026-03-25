class MinStack {
public:
stack<int>s;
stack<int>minSt;
    MinStack() {
        
    }
    
    void push(int val) {
    s.push(val);
    if(minSt.empty() || val<=minSt.top())
    minSt.push(val);
    }
    
    void pop() {
        if(s.top() == minSt.top())
        minSt.pop();

        s.pop();    
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */