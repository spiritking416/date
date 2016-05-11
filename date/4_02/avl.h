/*************************************************************************
	> File Name: avl.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月02日 星期六 09时31分50秒
 ************************************************************************/

#ifndef _AVL_H
#define _AVL_H

#include"Bitree.h"

template<class type>
class avl:public Bitree<type>
{
    public:
        avl();
        Binode<type>* root;
        void insert(const type& value);  //插入操作 
        void insert(Binode<type>*& node); 
        virtual ~avl();  
};


#endif
