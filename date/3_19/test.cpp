/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Mar 2016 03:37:45 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool lessthan(const int& a,const int& b){
    return a>b;
}

int main()
{
    vector<int> a={5,6,1,-1,8};
    sort(a.begin(),a.end(),lessthan);
    for(int i=0;i<a.size();++i)
    cout<<a[i]<<endl;

}

