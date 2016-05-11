/*************************************************************************
	> File Name: queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月16日 星期六 20时58分51秒
    用两个栈实现一个队列
 ************************************************************************/

#include<iostream>
#include<stack>

using namespace std;

template<typename type>
class my_queue{
private:
    stack<type> first;
    stack<type> second;
public:
    void insert_queue(const type& val){
        first.push(val);
    }
    void delete_queue(){
        while(!first.empty()){
            auto tmp=first.top();
            first.pop();
            second.push(tmp);
        }
        cout<<second.top()<<' ';
        second.pop();
        while(!second.empty()){
            auto tmp=second.top();
            second.pop();
            first.push(tmp);
        }
    }
};

int main(){
    my_queue<int> s;
    for(int i=0;i<5;++i){
        s.insert_queue(i);
    }
    for(int i=0;i<5;++i){
        s.delete_queue();
    }
    cout<<endl;
}
