class MinStack {
private:
    stack<int> s;      // main stack
    stack<int> minSt;  // stack to track minimums

public:
    MinStack() {
    }

    void push(int val) {
        s.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (s.top() == minSt.top()) {
            minSt.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minSt.top();
    }
};