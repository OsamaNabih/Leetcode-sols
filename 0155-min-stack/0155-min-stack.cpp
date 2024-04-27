class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(make_pair(val, val));
            return;
        }
        auto top = st.top();
        st.push(make_pair(val, min(val, top.second)));
    }
    
    void pop() {
        st.pop();
        
    }
    
    int top() {
        auto top = st.top();
        return top.first;
    }
    
    int getMin() {
        auto top = st.top();
        return top.second;
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