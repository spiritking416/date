/*************************************************************************
	> File Name: rbtree.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月05日 星期二 08时01分04秒
 ************************************************************************/

#ifndef _RBTREE_H
#define _RBTREE_H

#include"Bitree.h"

const int RED=0;
const int BLACK=1;

template<class type>
struct BLnode:public Binode<type>
{
    int color;       //0为红色 1为黑色
    BLnode<type>* lc=nullptr;
    BLnode<type>* rc=nullptr;
    BLnode<type>* p=nullptr;
};

template<class type>
class redblacktree:public Bitree<type>
{
    public:
        BLnode<type>* root;
        BLnode<type>* nil;                     //哨兵
        redblacktree();
        ~redblacktree(); 
        void leftrotate(BLnode<type>* node);  //左旋 
        void rightrotate(BLnode<type>* node); //右旋 
        void insert(BLnode<type>* node);      //插入节点
        void insert_fixup(BLnode<type>* node);//旋转调整
        void preorder(BLnode<type>* node);    //前序遍历
        void inorder(BLnode<type>* node);     //中序遍历
        void postorder(BLnode<type>* node);   //后序遍历  
        void levelorder(BLnode<type>* node);  //层序遍历
        bool search(type& value);        //搜索节点
        bool search(type& value,BLnode<type>* p);
        //virtual void remove(const type& value);          //删除节点
        //virtual void remove(BLnode<type>*& node);
        Binode<type>* successor(BLnode<type>*& node);    //寻找后继
        Binode<type>* successor(const type& value); 
        Binode<type>* predecessor(BLnode<type>*& node);  //寻找前驱
        Binode<type>* predecessor(const type& value); 
        
};


#   endif
