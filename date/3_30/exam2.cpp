/*************************************************************************
	> File Name: exam2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月30日 星期三 13时55分51秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<algorithm>

using namespace std;

//从vec中找出最接近n的一个或几个数之和
void _find(const int& n,int& r,int& _max,int& m, vector<int>& vec,unsigned int index){
    if(index>=vec.size()){
        if(_max<m)
            _max=m;
        return;
    } 
    r-=vec[index];
    if(m+vec[index]<=n){
        m+=vec[index];
        _find(n,r,_max,m,vec,index+1);
        m-=vec[index];
    }
    if(r+m>_max)           //剪枝
        _find(n,r,_max,m,vec,index+1);
    r+=vec[index];
}


int func(vector<int>& vec){
    if(vec.empty())   return 0;
    int n=0;
    int num=0;
    auto it=vec.end()-1;
    int max=0;
    sort(vec.begin(),vec.end()); 
    n=*it;
    vec.erase(it);
    vector<int> _delete(vec.size(),0);

    return num;
}

int main(){
    int m,n;
   /* while(cin>>m>>n){
        if(m==0 && n==0)    break;  //测试用例结束
        string str;   //描述颜色的字符串
        getline(cin,str);
        vector<string> color;
        auto it=str.begin();
        string tmp;
        while(it!=str.end()){  //读取颜色
            if(*it!=' ')
                tmp.push_back(*it);
            else{
                color.push_back(tmp);
                tmp.clear();
            }
            ++it;
        }
        
        vector<vector<int> > vec(color.size()); //同一颜色衣服各自洗涤时间
        for(int i=0;i<n;++i){//衣服洗涤时间和颜色
            getline(cin,str);
            string _time;
            int time;
            string _color;
            it=str.begin();

            while(*it!=' ' && *it<='9' && *it>='0'){
                _time.push_back(*it);
                ++it;
            } 
            ++it;

            while(it!=str.end()){   
                _color.push_back(*it);
            }

            time=atoi(_time.c_str());
            unsigned int index=0;
            for(;index<color.size();++index){
                if(_color==color[index])
                break;  
            }
            vec[index].push_back(time);   //记录第i种颜色衣服的洗涤时间
        }

        

    }*/
    vector<int> vec;
    int tmp=0;
    while(cin>>tmp){
        vec.push_back(tmp);
    }
    int r=accumulate(vec.begin(),vec.end(),0);
    n=100;
    m=0;
    int max=0;
    _find(n,r,max,m,vec,0);
    cout<<max<<endl;
}
