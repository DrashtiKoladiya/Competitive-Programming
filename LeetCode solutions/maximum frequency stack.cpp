class FreqStack {
public:
    map<int,int> m;
    map<int,stack<int>> m1;
    int mxf=0;
    
    FreqStack() {
        m.clear();
        m1.clear();
        mxf=0;
    }
    
    void push(int val) {
        mxf = max(mxf,m[val]+1);
        m[val]++;
        
        m1[m[val]].push(val);
    }
    
    int pop() {
        int x=m1[mxf].top();
        m1[mxf].pop();
        
        m[x]--;
        if(m1[mxf].size()==0)
        {
            mxf--;
        }
        
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */