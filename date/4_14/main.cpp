/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月14日 星期四 09时49分20秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include"sort.cpp"

using namespace std;

int main(){
    int a[]={2,5,3,0,2,3,0,3};
    int b[8];
    vector<int> A(a,a+8);
    vector<int> B(A.size(),0);
    int k=5;
    //counting_sort(A.begin(),A.end(),B.begin(),k);
    counting_sort(a,a+8,b,k);
    for(auto& i:a)
        cout<<i<<' ';
    cout<<endl;
    for(auto& i:b)
        cout<<i<<' ';
    cout<<endl;

}
