/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月01日 星期五 09时37分14秒
 ************************************************************************/

#include<iostream>
#include"Bitree.cpp"
#include<vector>

using namespace std;

int main(){
    Bitree<int> tree;
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
    cout<<"**********"<<endl;
    tree.preorder(tree.root);
    //tree.inorder(tree.root);
    cout<<"**********"<<endl;
    tree.inorder(tree.root);
    cout<<"**********"<<endl;
    cout<<"**********"<<endl;
    tree.levelorder(tree.root);
    cout<<"**********"<<endl;
    cout<<endl;
    //Binode<int>* tmp=tree.successor(t);
    //if(tmp!=nullptr)
    //    cout<<tmp->val<<endl;
    //tmp=tree.predecessor(13);
    //if(tmp!=nullptr)
    //    cout<<tmp->val<<endl;
    //cout<<tree.search(3)<<endl;
    //
    tree.remove(t);
    tree.levelorder(tree.root);
    cout<<"**********"<<endl;
}
