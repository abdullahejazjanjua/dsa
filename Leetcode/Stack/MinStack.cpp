#include <stack>
class MinStack {
public:
    stack<int> min_stack;
    stack<int> min_val_stack;
    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        min_stack.push(val);
        if (min_val_stack.empty() || val <= min_val_stack.top())
        {
            min_val_stack.push(val);
        }
    }
    
    void pop() 
    {
        int val = min_stack.top();
        min_stack.pop();
        if (!min_val_stack.empty() && val == min_val_stack.top()) 
            min_val_stack.pop();
    }
    
    int top() 
    {
        return min_stack.top();
    }
    
    int getMin() 
    {
        int val = 0;
        if (!min_val_stack.empty())
           val = min_val_stack.top();  
        return val;  
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