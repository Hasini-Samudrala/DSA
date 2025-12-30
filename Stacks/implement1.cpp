/*
problem link - https://leetcode.com/problems/implement-stack-using-queues/description/
*/

//approach
class MyStack {
private:

    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
         int n = q.size(); 

        for(int i=0; i<n-1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top=q.front();
        q.pop();
        return top;
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
 push is like u need to push to the first element
 so basically u push to the emd and then u push all the last element to the first in order nd pop that last element
 */