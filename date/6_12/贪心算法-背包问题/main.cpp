/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Jun 2016 09:38:00 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

#include"sort.cpp"

using namespace std;



void Sort(const int& n,vector<float>& v,vector<float>& w){
    vector<float> vec;
    for(int i=0;i<n;++i){
        //单位重量的价值
        vec.push_back(v[i]/w[i]);
    }
    quicksort(vec.begin(),vec.end());
}

//M 背包总量 w 物品重量集合 v 物品价值结合
void 
Knapsack(const int& n,float M,vector<float>& v ,vector<float>& w,vector<float>& x){
    Sort(n,v,w);    
    int i;
    for(auto& i:x)
       i=0; 
    float c=M;
    for(i=0;i<n;++i){
        if(w[i]>c) break;
        x[i]=1;
        c-=w[i];
    }
    if(i<n) x[i]=c/w[i];
}

int
main(){
    
}
