/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月22日 星期五 09时23分14秒
    测试socket结构大小
 ************************************************************************/

#include<iostream>
#include<netinet/in.h>
#include<sys/socket.h>

using namespace std;


int main(){
    struct sockaddr_in so;
    struct sockaddr_in6 sso;
    struct sockaddr in;
    cout<<sizeof(so)<<endl;
    cout<<sizeof(sso)<<endl;
    cout<<sizeof(in)<<endl;
}
