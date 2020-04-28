#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

class MinStack {
public:
    int TOP;
    vector<int>stk;
    vector<int> min;
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push_back(x);
        if(min.empty() || x<=min.back() ){
            min.push_back(x);
        }
    }
    
    void pop() {
        if(stk.back()==min.back()){
            min.pop_back();
        }
        stk.pop_back();
    }
    
    int top() {
        if(!stk.empty())
            return stk.back();
        return -1;
    }
    
    int getMin() {
        if(!min.empty())
            return min.back();
        return -1;
    }
};

//driver code;
int main(){
    FAST_IO;
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout<<obj->getMin()<<"\n";
    obj->pop();
    obj->top();
    cout<<obj->getMin()<<"\n";
    return 0;
}
