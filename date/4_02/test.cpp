/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月02日 星期六 10时38分11秒
 ************************************************************************/

#include<iostream>
using namespace std;

class base{
    public:
        int a;
    base(){
        a=-1;
    }

};

class son:public base
{
    public:
    son(){
        a=5;
    }
    void f(){
        cout<<base::a<<endl;
    }
};

int main(){
    son s;
    cout<<s.a<<endl;
    s.f();
}
