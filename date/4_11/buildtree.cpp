/*************************************************************************
	> File Name: buildtree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月09日 星期六 20时19分21秒
    根据前序遍历和中序遍历重建二叉树
 ************************************************************************/

#include<iostream>
#include<stack>
#include<vector>
#include<exception>
#include"Bitree.h"
using namespace std;

template<class type,class T>
Binode<type>* buildtree(T preorder,T inorder,const int& length,Binode<type>* flag){
    //if(preorder==nullptr || inorder==nullptr || length<=0)
    //    return nullptr;
    Binode<type>* last=nullptr;
    return ConstructCore(preorder,preorder+length,inorder,inorder+length,last);
}


template<class type,class T>
Binode<type>* ConstructCore(T startPreorder,T endPreorder,T startInorder,T endInorder,Binode<type>*& last){
    //前序遍历序列的第一个数字是根结点的值
    int rootValue=startPreorder[0];
    auto root=new Binode<type>;
    root->val=rootValue;
    if(last!=nullptr)
        root->p=last;
    if(startPreorder==endPreorder-1){
        if(startInorder==endInorder-1 && *startPreorder==*endPreorder){
            return root;
        }
        //else
            //throw exception("Invalid input.");
    }
    //在中序遍历中知道根结点的值
    auto rootInorder=startInorder;
    while(rootInorder<endInorder && *rootInorder!=rootValue){
        ++rootInorder;
    }
    int leftLength=rootInorder-startInorder;
    auto leftPreorderEnd=startPreorder+leftLength+1;
    if(leftLength>0){
        //构建左子树
        root->lc=ConstructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInorder,root);
    }
    if(leftLength<endPreorder-startPreorder-1)
    {
        //构建右子树
        root->rc=ConstructCore(leftPreorderEnd,endPreorder,rootInorder+1,endInorder,root);
    }

    return root;
}

template<class type>
void destroy(Binode<type>*& root){
    auto ptr=root;
    auto p=ptr;
    stack<Binode<type>* > sta;
    while(!sta.empty() || ptr!=nullptr){
        if(ptr!=nullptr){
            sta.push(ptr);
            ptr=ptr->lc;
        }
        else{
            p=sta.top();
            sta.pop();
            ptr=p->rc;
            delete p;
        }
    }
}

/*
template<class type>
void preorder(Binode<type>* node){
    if(node!=nullptr){
        cout<<node->val<<' ';
        preorder(node->lc);
        preorder(node->rc);
    }  
}*/


template<class type>
void preorder(Binode<type>* node){
    if(node!=nullptr){
        stack<Binode<type>* > sta;
        auto ptr=node;
        while(!sta.empty() || ptr!=nullptr){
            if(ptr!=nullptr){
                cout<<ptr->val<<' ';
                sta.push(ptr);
                ptr=ptr->lc;
            }
            else{
                ptr=sta.top();
                ptr=ptr->rc;
                sta.pop();
            }
        }
        cout<<endl;


    }
}


template<class type>
void inorder(Binode<type>* node){
    if(node!=nullptr){
        auto ptr=node;
        stack<Binode<type>* > sta;
        while(ptr!=nullptr || !sta.empty()){
            if(ptr!=nullptr){
                sta.push(ptr);
                ptr=ptr->lc;
            }
            else{
                ptr=sta.top();
                cout<<ptr->val<<' ';
                ptr=ptr->rc;
                sta.pop();
            }
        }
    }  
}


int main(){
    int tmp;
    vector<int> pre;
    vector<int> in;
    while(cin>>tmp){
        pre.push_back(tmp);
        if(cin.get()=='\n')
            break;
    }
    while(cin>>tmp){
        in.push_back(tmp);
        if(cin.get()=='\n')
            break;
    }
    int length=pre.size();
    cout<<length<<endl;
    Binode<int>* root=nullptr;
    root=buildtree(pre.begin(),in.begin(),length,root);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    destroy(root); 
}
