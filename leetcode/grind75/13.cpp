#include "bits/stdc++.h"

using namespace std;

class MyQueue {
    stack<int> main_stack;
    stack<int> shelf_stack;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // Empty the main into the shelf, insert x, then put back the stack
        while(!main_stack.empty()) {
            shelf_stack.push(main_stack.top());
            main_stack.pop();
        }

        // Actually insert x
        main_stack.push(x);

        // Push back the other elements
        while(!shelf_stack.empty()) {
            main_stack.push(shelf_stack.top());
            shelf_stack.pop();
        }
    }
    
    int pop() {
        int x = main_stack.top();
        main_stack.pop();
        return x;
    }
    
    int peek() {
        return main_stack.top();
    }
    
    bool empty() {
        return main_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */