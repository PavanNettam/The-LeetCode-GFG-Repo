class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int temp;
        while(!q1.empty()){
            temp = q1.front();
            q2.push(temp);
            q1.pop();
        }
        int ans = temp;
        while(!q2.empty()){
            temp = q2.front();
            if(temp != ans){
                q1.push(temp);
            }
            q2.pop();
        }
        return ans;
    }
    
    int top() {
        int temp;
        while(!q1.empty()){
            temp = q1.front();
            q2.push(temp);
            q1.pop();
        }
        int ans = temp;
        while(!q2.empty()){
            temp = q2.front();
            q1.push(temp);
            q2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return q1.empty();
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