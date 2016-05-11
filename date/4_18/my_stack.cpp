/*************************************************************************
	> File Name: my_stack.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月18日 星期一 19时00分32秒
    用两个队列实现一个栈
 ************************************************************************/

#include<iostream>
#include<queue>

using namespace std;

template<typename type>
class my_stack{
private:
    queue<type>* first;
    queue<type>* second;
    int size;
public:
    my_stack(){
        first=new queue<type>;
        second=new queue<type>;
        size=0;
    }
    void push(const type& val){
        first->push(val);
        ++size;
    }
    type top(){
        if(this->empty())   return -1;
        type tmp;
        while(!first->empty()){
            tmp=first->front();;
            first->pop();
            second->insert(tmp);
        }
        queue<type>* i=first;
        first=second;
        second=i;
    }
    void pop(){
        if(size<=0) return;
        type tmp;
        for(int i=size;i>1;--i){
            tmp=first->front();
            first->pop();
            second->push(tmp);
        }
        cout<<first->front()<<' ';
        first->pop();
        queue<type>* i=first;
        first=second;
        second=i;
        --size;
    }
    bool empty(){
        if(size==0)
            return true;
        return false;
    }
    ~my_stack(){
        delete first;
        delete second;
    }
};

int main(){
    my_stack<int> stack;
    for(int i=0;i<6;++i){
        stack.push(i);
    }
    while(!stack.empty()){
        stack.pop();
    }
    cout<<endl;
}
