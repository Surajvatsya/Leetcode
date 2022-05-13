class MyStack {
public:
    //rem -> 2 queue lena hota h
    queue<int>q1;
    queue<int>q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty() && q2.empty())    return -1;
        
        if(q2.empty()){
                while(!q1.empty()){
                int ele = q1.front();
                q1.pop();
                q2.push(ele);
            }
        }
        
        int n = q2.size();
        
        while(n>1){
            
         int ele = q2.front();
          q2.pop(); 
            q2.push(ele);
            n--;
        }
         int ele = q2.front();
         q2.pop(); 
        return ele;
        
    }
    
    int top() {
        
        if(!q1.empty()){
           return q1.back(); 
        }
        return q2.back();
            
        
    }
    
    bool empty() {
        if(q1.empty() and q2.empty())
            return true;
        return false;
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