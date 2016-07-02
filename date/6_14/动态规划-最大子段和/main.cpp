/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 14 Jun 2016 08:13:21 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int
MaxSum(const int &n,vector<int>& a){
    if(n>a.size()) return -1;
    int sum=0;
    int b=0;
    for(int i=0;i<n;++i){
        if(b>0) b+=a[i];
        else b=a[i];
        if(b>sum) sum=b;
    }
    return sum;
}

int
main(){
    vector<int> a{4,1,3,-5,2,5,-7,3};
    cout<<MaxSum(8,a)<<endl;
}
