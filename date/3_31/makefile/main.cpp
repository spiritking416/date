/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月31日 星期四 16时59分07秒
 ************************************************************************/

#include<iostream>
#include"nqueen.h"
#include<vector>

using namespace std;

int main()
{
        int sum=0;
        int n;
        cin>>n;
        vector<int> vec(n,0);
        nqueen(vec,0,sum);
        cout<<sum<<endl; 

}
