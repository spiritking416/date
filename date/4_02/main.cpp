/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月02日 星期六 09时31分55秒
 ************************************************************************/


#include<iostream>
#include"avl.cpp"
#include<vector>

using namespace std;

int main(){
    avl<int> tree;
    vector<int> vec;
    int u;
    int t;
    cin>>t;
    while(cin>>u){
        vec.push_back(u);
    }
    for(unsigned int i=0;i<vec.size();++i){
        Binode<int>* tmp=new Binode<int>;
        tmp->val=vec[i];
        tree.insert(tmp);
    }
    //tree.preorder(tree.root);
    //tree.inorder(tree.root);
    cout<<"**********"<<endl;
    tree.levelorder(tree.root);
    cout<<"**********"<<endl;
    //cout<<endl;
    //Binode<int>* tmp=tree.successor(t);
    //if(tmp!=nullptr)
    //    cout<<tmp->val<<endl;
    //tmp=tree.predecessor(13);
    //if(tmp!=nullptr)
    //    cout<<tmp->val<<endl;
    //cout<<tree.search(3)<<endl;
    //
    //tree.remove(t);
    //tree.levelorder(tree.root);
    //cout<<"**********"<<endl;
}
