/*************************************************************************
	> File Name: place.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月31日 星期四 20时46分45秒
 ************************************************************************/

#include<vector>
#include"place.h"
#include<cmath>
using namespace std;

bool place(int& t,vector<int>& vec){
    for(int i=0;i<t;++i){
                if(abs(i-t)==abs(vec[i]-vec[t]) || vec[i]==vec[t])
                    return false;
            
    }
        return true;



}
