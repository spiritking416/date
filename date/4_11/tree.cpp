/*************************************************************************
	> File Name: tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月07日 星期四 10时16分02秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


int main(){
    vector<int> pre;
    vector<int> in;
    int tmp;
    while(cin>>tmp){
        if(cin.get()=='\n') break;
        pre.push_back(tmp);
    }
    int size=pre.size();
    for(int i=0;i<size;++i){
        cin>>tmp;
        in.push_back(tmp);
    }
    auto ptr=new TreeNode(pre[0]);
    stack<TreeNode*> sta;;
    sta.push(ptr)
    int index=1;
    int pos;
    while(index<size){
        auto p=new TreeNode(pre[index]);
        for(int i=0;i<size;++i){
            if(in[i]==pre[index]){
                pos=i;
                break;
            }
        }
        
    }
}
