/*************************************************************************
	> File Name: nqueen.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月31日 星期四 16时56分01秒
 ************************************************************************/

#include<iostream>
#include"nqueen.h"
#include"place.h"
#include<cmath>

using namespace std;

void nqueen(vector<int>& vec,int t,int& sum){
    if(t<0) return;
  
    if(t>=vec.size()){
        ++sum;
        cout<<"***********"<<endl;
        for(unsigned int i=0;i<vec.size();++i){
            for(int j=0;j<vec.size();++j){
                if(vec[i]==j)
                    cout<<1<<' ';
                else
                    cout<<0<<' ';
            }
            cout<<endl;
        }   
        cout<<"***********"<<endl;
        return;
    }

    for(unsigned int j=0;j<vec.size();++j){
        vec[t]=j;      //第t层的皇后摆在第j列
        if(place(t,vec))
            nqueen(vec,t+1,sum);
            
    }
}
