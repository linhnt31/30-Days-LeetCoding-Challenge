// Method 1: Using pair
// Time complexity: O(1) ... Space complexity: O(n)
class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> s;
    MinStack() {
        
    }
    
    void push(int x) {
        if(s.empty()) {
            s.push({x, x});
        }
        else{
            s.push({x, min(x, s.top().second)});
        }
    }
    
    void pop() {
        if(!s.empty()){
            s.pop();
        }
    }
    
    int top() {
        if(!s.empty()){
            return s.top().first;
        }
        return NULL;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */