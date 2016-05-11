/*************************************************************************
	> File Name: question.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月30日 星期三 21时26分39秒

    求数组中最接近最大值的若干数字组合
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//递归解法
//c:背包重量 w:当前已装物品重量 bestw:最大装载物品重量 r:物品剩余重量,vec:物品重量集合 road:记录装载的物品 bestr:最优解对应的装载的物品
void backtrack(int& c,int& w,int& bestw,int& r,unsigned int index,vector<int>& vec,vector<int>& road,vector<int>& bestr){
    if(index>=vec.size()){
        if(bestw<w) 
        {
            bestw=w;
            copy(road.begin(),road.end(),bestr.begin());
        }
        return;
    }
    r-=vec[index];
    if(w+vec[index]<=c){//搜索左子树
        w+=vec[index];
        road[index]=1;
        backtrack(c,w,bestw,r,index+1,vec,road,bestr);
        w-=vec[index];
    }
    if(bestw<w+r){//剪枝后搜索右子树
        road[index]=0;
        backtrack(c,w,bestw,r,index+1,vec,road,bestr);
    }
    r+=vec[index];
}

//迭代解法
//c:背包重量 w:当前已装物品重量 bestw:最大装载物品重量 r:物品剩余重量,vec:物品重量集合 road:记录装载的物品 bestr:最优解对应的装载的物品
void backtrack(int& c,vector<int>& vec,vector<int>& bestr){
    vector<int> road(vec.size(),0);
    int w=0;
    int r=accumulate(vec.begin(),vec.end(),0);
    int bestw=0;
  

}

int main(){
    vector<int> vec;
    int tmp;
    int c;
    int w=0;
    int bestw=0;
    cin>>c;
    while(cin>>tmp){
        vec.push_back(tmp);
    }
    int r=accumulate(vec.begin(),vec.end(),0);
    vector<int> road(vec.size(),0);
    vector<int> bestr(road);
    backtrack(c,w,bestw,r,0,vec,road,bestr);
    cout<<"**************"<<endl;
    cout<<bestw<<endl;
    cout<<"**************"<<endl;
    for(unsigned int i=0;i<vec.size();++i)
    {
        if(bestr[i]==1)
            cout<<vec[i]<<endl;
    }
}

