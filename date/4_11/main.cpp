/*************************************************************************
    > File Name: main.cpp
    > Author: 
    > Mail: 
    > Created Time: 2016年04月06日 星期三 09时02分16秒
 ************************************************************************/

#include<iostream>
#include"rbtree.cpp"

using namespace std;

int main(){
    redblacktree<char> tree;
    char tmp;
    while(cin>>tmp){
        auto p=new BLnode<char>;
        p->val=tmp;
        tree.insert(p);
    }
    //tree.inorder(tree.root);
    tree.levelorder(tree.root);
}

