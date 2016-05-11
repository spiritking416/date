/*************************************************************************
	> File Name: maxheap.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月13日 星期三 10时48分10秒
 ************************************************************************/

#ifndef _MAXHEAP_H
#define _MAXHEAP_H
#include<vector>
#include"../4_11/Bitree.h"

using namespace std;

//最大堆
class maxheap{
public:
    maxheap();

    template<typename type>
    maxheap(type vec,const int& size,const int& heap_size);

    template<typename type>
    void build_max_heap(type vec,const int& size,const int& heap_size);

    template<typename type>
    void max_heapify(type vec,const int& i);

    template<typename type>
    void heapsort(type vec,const int& size);

    int left(const int& i);
    int right(const int& i);
    ~maxheap();
private:
    int length;
    int heapsize;
};

#endif
