#include <stack>

class MyQueue {
private:
    std::stack<int> in_stack;
    std::stack<int> out_stack;

    // Helper: moves elements from in_stack to out_stack when out_stack is empty
    void transfer() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
    }

public:
    MyQueue() {
        // Stacks initialize empty automatically
    }
    
    void push(int x) {
        in_stack.push(x);
    }
    
    int pop() {
        transfer();
        int val = out_stack.top();
        out_stack.pop();
        return val;
    }
    
    int peek() {
        transfer();
        return out_stack.top();
    }
    
    bool empty() {
        return in_stack.empty() && out_stack.empty();
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