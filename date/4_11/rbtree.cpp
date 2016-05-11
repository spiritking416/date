/*************************************************************************
	> File Name: rbtree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月05日 星期二 08时00分33秒
    红黑树
 ************************************************************************/

#include<iostream>
#include<stack>
#include"rbtree.h"
#include"Bitree.cpp"

using namespace std;

template<class type>
redblacktree<type>::redblacktree(){
    nil=new BLnode<type>;
    nil->color=BLACK;
    root=nil;
}


template<class type>
void redblacktree<type>::leftrotate(BLnode<type>* node){
    if(node==nil || node==nullptr)   return;
    auto right=node->rc;
    if(right==nil)   return;
    node->rc=right->lc;
    if(right->lc!=nil)
        right->lc->p=node;
    right->p=node->p;          //如果是传入指针的引用，node就为空
    if(node->p==nil)
        root=right;
    else if(node==node->p->lc)       
        node->p->lc=right;
    else
        node->p->rc=right;
    node->p=right;
    right->lc=node;
}

template<class type>
void redblacktree<type>::rightrotate(BLnode<type>* node){
    if(node==nil || node==nullptr)   return;
    auto left=node->lc;
    if(left==nil) return;
    node->lc=left->rc;
    if(left->rc!=nil)
        left->rc->p=node;
    left->p=node->p;
    if(node->p==nil)
        root=left;
    else if(node->p->rc==node)
        node->p->rc=left;
    else
        node->p->lc=left;
    node->p=left;
    left->rc=node;
}

template<class type>
void redblacktree<type>::inorder(BLnode<type>* node){
    if(node!=nullptr && node!=nil){
        auto ptr=node;
        stack<BLnode<type>* > sta;
        while(ptr!=nil || !sta.empty()){
            if(ptr!=nil){
                sta.push(ptr);
                ptr=ptr->lc;
            }
            else{
                ptr=sta.top();
                cout<<ptr->val;
                if(ptr->color==RED)
                    cout<<"RED"<<' ';
                else
                    cout<<"BLACK"<<' ';
                ptr=ptr->rc;
                sta.pop();
            }
        }
    }  
}

template<class type>
void redblacktree<type>::levelorder(BLnode<type>* node){
    if(node==nullptr) return;
    deque<BLnode<type>*> queue;
    queue.push_back(node);         //有问题
    int index=queue.size();
    while(!queue.empty()){
        while(index!=0){
            cout<<queue[0]->val;
            if(queue[0]->color==RED)
                cout<<"RED"<<' ';
            else
                cout<<"BLACK"<<' ';
            --index;
            if(queue[0]->lc!=nil)
               queue.push_back(queue[0]->lc);
            if(queue[0]->rc!=nil)
               queue.push_back(queue[0]->rc);
            queue.pop_front();
        }
        index=queue.size();
        cout<<endl;
    }   
}


template<class type>
void redblacktree<type>::insert(BLnode<type>* node){
    if(node==nullptr || node==nil)   return;
    BLnode<type> *p,*s;
    p=nil;
    s=root;
    while(s!=nil){
        p=s;
        if(node->val<=s->val)
        {
            s=s->lc;
        }
        else
        {
            s=s->rc;
        }
        
    }
    node->p=p;
    if(p==nil)
    {
        root=node;
    }
    else{
        if(node->val<=p->val)
        {
            p->lc=node;
        }
        else{
            p->rc=node;
        }
    }
    node->lc=nil;
    node->rc=nil;
    node->color=RED;
    insert_fixup(node);   //调整红黑树
}

template<class type>
void redblacktree<type>::insert_fixup(BLnode<type>* node){
    while(node->p->color==RED){
        if(node->p==node->p->p->lc){         //node->p是左孩子
            auto unclenode=node->p->p->rc;   //叔结点
            if(unclenode->color==RED){
                node->p->color=BLACK;
                unclenode->color=BLACK;
                node->p->p->color=RED;
                node=node->p->p;
                continue;
            }
            else if(node==node->p->rc){
                node=node->p;
                leftrotate(node);
            }
            node->p->color=BLACK;
            node->p->p->color=RED;
            rightrotate(node->p->p);
        }
        else                                 //node->p是右孩子
        { 
            auto unclenode=node->p->p->lc;   //叔结点
            if(unclenode->color==RED){
                node->p->color=BLACK;
                unclenode->color=BLACK;
                node->p->p->color=RED;
                node=node->p->p;
                continue;
            }
            else if(node==node->p->lc){
                rightrotate(node);
                node=node->rc;                //顺序和左旋相反
            }
            node->p->color=BLACK;
            node->p->p->color=RED;
            leftrotate(node->p->p);
            
        }
    } 
    root->color=BLACK;
}

template<class type>
redblacktree<type>::~redblacktree(){
    auto ptr=root;
    auto p=ptr;
    stack<BLnode<type>* > sta;
    while(!sta.empty() || ptr!=nil){
        if(ptr!=nil){
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
    delete nil;
    nil=nullptr;
    root=nullptr;
}

