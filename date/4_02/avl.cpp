/*************************************************************************
	> File Name: avl.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月02日 星期六 09时31分42秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include"Bitree.cpp"
#include"avl.h"

using namespace std;

template<class type>
avl<type>::avl(){
    root=nullptr;   //在class外使用时要加范围
}

template<class type>
void avl<type>::insert(const type& value){
    Binode<type>* ptr=search(value); 
    if(ptr==nullptr)
        return;
    insert(ptr);
}

template<class type>
void avl<type>::insert(Binode<type>*& node){
    
}

template<class type>
avl<type>::~avl(){
    delete root;
}

