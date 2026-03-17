#include <bits/stdc++.h>

using namespace std;

class MinStack {
private:
    stack<int> values;
    stack<int> minimums;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        values.push(val);
        minimums.push(min(getMin(),val));
    }
    
    void pop() {
        values.pop();
        minimums.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        if(minimums.size() == 0) return INT_MAX;
        return minimums.top();
    }
};

int main() {
    
    return 0;
}