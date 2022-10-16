class MyQueue {
public:
    stack<int> in;
    stack<int> out;
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(out.size() != 0){
            int ret = out.top();
            out.pop();
            return ret;
        }else{
            int n = in.size();
            for(int i=0;i<n-1;i++){
                int temp = in.top();
                in.pop();
                out.push(temp);
            }
            int ret = in.top();
            in.pop();
            return ret;
        }
    }
    
    int peek() {
        if(out.size() != 0){
            int ret = out.top();
            return ret;
        }else{
            int n = in.size();
            for(int i=0;i<n-1;i++){
                int temp = in.top();
                in.pop();
                out.push(temp);
            }
            int ret = in.top();
            in.pop();
            out.push(ret);
            return ret;
        }
    }
    
    bool empty() {
        if(in.size() == 0 && out.size() == 0){
            return 1;
        }
        return 0;
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