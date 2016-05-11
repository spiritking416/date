/*************************************************************************
	> File Name: rbtree.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月05日 星期二 08时01分04秒
 ************************************************************************/

#ifndef _RBTREE_H
#define _RBTREE_H

#include"Bitree.h"

template<class type>
strut BLnode{
    int color;
    type val;
    BLnode* lc=nullptr;
    BLnode* rc=nullptr;
    BLnode* p=nullptr;
}

template<class type>
class redblacktree:public Bitree<type>
{
    
};


#endif
