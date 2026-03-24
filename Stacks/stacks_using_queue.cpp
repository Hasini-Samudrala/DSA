/*
problem link - https://leetcode.com/problems/implement-stack-using-queues/description/
*/
class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);

        int size= q.size();
        for(int i=0;i<size-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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

 /*
 After every push, rotate the queue so that the newest element comes to the front → behaving like a stack.
 Every push does this:
“Push new element → move all old elements behind it”
So newest element always comes to the front

 */