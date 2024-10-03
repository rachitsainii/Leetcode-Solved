class MinStack {
private:
    int *stack;
    int *minStack;
    int topIndex;
    int minIndex;
    int capacity;

public:
    MinStack() {
        capacity = 30000;
        stack = new int[capacity];
        minStack = new int[capacity];
        topIndex = -1;
        minIndex = -1;
    }
    
    void push(int val) {
        topIndex++;
        stack[topIndex] = val;

        if(minIndex == -1 || val <= minStack[minIndex]){
            minIndex++;
            minStack[minIndex] = val;
        }
    }
    
    void pop() {
        int poppedValue = stack[topIndex];
        topIndex--;

        if(poppedValue == minStack[minIndex]){
            minIndex--;
        }
    }
    
    int top() {
        return stack[topIndex];
    }
    
    int getMin() {
        return minStack[minIndex];
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