/*************************************************************************
	> File Name: knapsack.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月31日 星期四 21时47分48秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//wlimit:背包限重 cw:当前背包载重 cvalue:当前背包物品价值 bestvalue:最优价值 rvalue:剩余物品价值 index:递归深度
void backtrack(vector<int>& weight,vector<int>& value,vector<int>& road,vector<int>& bestroad,int& wlimit,int& cw,int& cvalue,int& bestvalue,int& rvalue,unsigned int index){ 
    if(index>=weight.size()){
        bestvalue=cvalue;
        copy(road.begin(),road.end(),bestroad.begin());
        return;
    }
    rvalue-=value[index];
    if(cw+weight[index]<=wlimit){
        cw+=weight[index];
        cvalue+=value[index];
        road[index]=1;
        backtrack(weight,value,road,bestroad,wlimit,cw,cvalue,bestvalue,rvalue,index+1);
        road[index]=0;
        cvalue-=value[index];
        cw-=weight[index];
    }
    if(cvalue+rvalue>bestvalue){
        road[index]=0;
        backtrack(weight,value,road,bestroad,wlimit,cw,cvalue,bestvalue,rvalue,index+1);
    }
    
    rvalue+=value[index];
}

int main(){
    int n;
    int wlimit;
    cin>>n;
    cin>>wlimit;
    vector<int> weight;
    vector<int> value;
    vector<int> road(n,0);
    vector<int> bestroad(n,0);
    int tmp;
    for(int i=0;i<n;++i){
        cin>>tmp;
        weight.push_back(tmp);
    }
    for(int i=0;i<n;++i){
        cin>>tmp;
        value.push_back(tmp);
    }
    int rvalue=accumulate(value.begin(),value.end(),0);
    int cw=0;
    int cvalue=0;
    int bestvalue=0;
    backtrack(weight,value,road,bestroad,wlimit,cw,cvalue,bestvalue,rvalue,0);
    cout<<bestvalue<<endl;
    cout<<"************"<<endl;
    for(int i=0;i<n;++i){
        if(bestroad[i]==1)
            cout<<value[i]<<' ';
    }
    cout<<endl;
    cout<<"************"<<endl;
}
