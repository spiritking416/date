/*************************************************************************
	> File Name: hash.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月12日 星期二 16时26分02秒
    哈希表
    除法散列法+链接法
 ************************************************************************/

#ifndef _HASH_H
#define _HASH_H

#include<vector>

using namespace std;

template<class type>
class hash_list{
public:
    type val;
    hash_list* pre;
    hash_list* next;  
    static int hash_list_size;
    hash_list(){
        val=0;
        pre=nullptr;
        next=nullptr;
    }
};

template<class type>
int hash_list<type>::hash_list_size=0;

template<class type>
class hash_table{
public:
    hash_table(vector<hash_list<type>* >*& hash_ptr,int m=10){
        if(m<0) m=10;
        hash_ptr=new vector<hash_list<type>* >(m,nullptr);
        ptr=hash_ptr;
    }
    ~hash_table(){
        delete ptr;
    }

private:
    vector<hash_list<type>* >* ptr;
};

#endif
