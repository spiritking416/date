/*************************************************************************
	> File Name: snakematrix.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月05日 星期二 20时51分12秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

void GetResult(int Num,char* pResult){
    char tmp=1;
    for(int i=0;i<Num;++i){
        char p=i;
        char q=0;
        while(p>=0 && q<=i){
            pResult[(2*Num-p+1)*p/2+q]=tmp;
            ++tmp;
            --p;
            ++q;
        }
    }
}

int main(){
    int num;
    while(cin>>num){
        char* p=new char[(1+num)*num/2+1];
        GetResult(num,p);
        for(int i=0;i<num;++i){
            for(int j=0;j<num-i;++j){
                printf("%d ",p[(2*num-i+1)*i/2+j]);
            }
            printf("\n");
        } 
    }
}
