class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int ele;
        int n = q.size();
        for(int i=0;i<n-1;i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        ele = q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        int ele;
        int n = q.size();
        for(int i=0;i<n-1;i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        ele = q.front();
        q.pop();
        q.push(ele);
        return ele;
    }
    
    bool empty() {
        if(q.size() == 0){
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */