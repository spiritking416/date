/*************************************************************************
	> File Name: Bitree.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月01日 星期五 08时40分24秒
 ************************************************************************/

#ifndef _BITREE_H
#define _BITREE_H

#include<iostream>
#include<deque>

using namespace std;

template<class type>
struct Binode{
    Binode<type>* p=nullptr;
    Binode<type>* lc=nullptr;
    Binode<type>* rc=nullptr;
    type val;
};

//二叉搜索树
template<class type>
class Bitree{
    public:
        Binode<type>* root;
        Bitree();
        void insert(Binode<type>* node);      //插入节点
        void preorder(Binode<type>* node);    //前序遍历
        void inorder(Binode<type>* node);     //中序遍历
        void postorder(Binode<type>* node);   //后序遍历  
        void levelorder(Binode<type>* node);  //层序遍历
        bool search(const type& value);       //搜索节点
        bool search(const type& value,Binode<type>*& p);
        virtual void remove(const type& value);       //删除节点
        virtual void remove(Binode<type>*& node);
        Binode<type>* successor(Binode<type>* node);  //寻找后继
        Binode<type>* successor(const type& value); 
        Binode<type>* predecessor(Binode<type>* node);  //寻找前驱
        Binode<type>* predecessor(const type& value); 
        virtual ~Bitree();
};

#endif
