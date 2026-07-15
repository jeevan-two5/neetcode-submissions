class MinStack {
private:
        stack<int>st,min_st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min_st.empty() || val <= min_st.top()) min_st.push(val);
    }
    
    void pop() {
        if(min_st.top() == st.top()) min_st.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
