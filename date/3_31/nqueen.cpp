/*************************************************************************
	> File Name: nqueen.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月31日 星期四 15时52分40秒

    n皇后问题,棋盘n×n
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

bool place(int& t,vector<int>& vec){
    for(int i=0;i<t;++i){
        if(abs(i-t)==abs(vec[i]-vec[t]) || vec[i]==vec[t])
            return false;
    }
    return true;
}

//t从0到n-1
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

int main()
{
    int sum=0;
    int n;
    cin>>n;
    vector<int> vec(n,0);
    nqueen(vec,0,sum);
    cout<<sum<<endl; 
}

