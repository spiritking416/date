/*************************************************************************
	> File Name: tecent_snake.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月05日 星期二 21时41分09秒
 ************************************************************************/

#include<iostream>

using namespace std;

int** getmatrix(const int& n){
    int** p=new int* [n];
    for(int i=0;i<n;++i)
        p[i]=new int[n];
    int tmp=1;
    int i=0;
    int j=0;
    int row=0;
    int col=0;
    int u=n*n;
    while(tmp<=u){
        for(i=row,j=col;j<n-col;++j){
            p[i][j]=tmp++;
        }
        for(i=row+1,j=n-col-1;i<n-row;++i){
            p[i][j]=tmp++;
        }
        for(i=n-row-1,j=n-col-2;j>=col;--j){
            p[i][j]=tmp++;
        }
        ++row;
        for(i=n-row-1,j=col;i>=row;--i){
            p[i][j]=tmp++;
        }
        ++col;
    }

    return p;
}

int main(){
    int** p;
    int n;
    while(cin>>n){
        p=getmatrix(n); 
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)
                cout<<p[i][j]<<' ';
            cout<<endl;
        }
        for(int i=0;i<n;++i){
            delete []p[i];
            p[i]=nullptr;
        }
        delete []p;
        p=nullptr;
    }
}
