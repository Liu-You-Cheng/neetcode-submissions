class MinStack {
public:
    std::stack<int> stk;
    std::stack<int> minstk;

    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        if(minstk.empty() || val <= minstk.top()){
            minstk.push(val);
        }
    }
    
    void pop() {
        int tp = stk.top();
        stk.pop();
        if(tp == minstk.top()){
            minstk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};
