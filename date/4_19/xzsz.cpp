/*************************************************************************
	> File Name: xzsz.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月19日 星期二 19时04分15秒
    旋转数组的最小值
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename type>
int Min(type first,type last){
    auto it=first;
    auto jt=last-1;
    auto mid=it;
    while(*it>=*jt){
        if(it==jt-1){
            mid=jt;
            break;
        }
        mid=it+(jt-it)/2;
        if(*mid>=*it)
            it=mid;
        else if(*mid<*jt)
            jt=mid;
    }
    return *mid;
}

int main(){
    vector<int> vec;
    int tmp;
    while(cin>>tmp){
        vec.push_back(tmp);
    }
    int minelem=Min(vec.begin(),vec.end());
    cout<<minelem<<endl;
}
