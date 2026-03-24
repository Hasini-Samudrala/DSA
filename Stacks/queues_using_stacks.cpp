#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/*
we use two stacks because like we cant make the first element as last element in teh stack as while we are implemeting 
queue we need to return the first elenent when asked for pop or peek , but i can access only last element using teh stack 
so i am using  two stacks here 

we use that second stack needed in teh pop and peek like we invert the whole stack and then take wht we wnat 
if we implement teh same in teh push , liek using teh two stacks in teh stack then it is a problem 
coz when there is only element or any elements , everytime u need to create a new stack and as teh stack 2 is delcred as
global variable it would be a problem , because we cant create a new stack in the push , as we cant access that stack in teh 
pop and peek again...and then it would be a problem , thats why we create that second stack aith full elements when we wnat 
that is in the pop and peek ......

*/