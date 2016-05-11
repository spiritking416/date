/*************************************************************************
	> File Name: maxheap.cpp
    > Author: 
	> Mail: 
	> Created Time: 2016年04月13日 星期三 10时47分19秒
    最大堆
 ************************************************************************/

#include<iostream>
#include<vector>
#include"maxheap.h"

using namespace std;

maxheap::maxheap(){
    length=0;
    heapsize=0;
}

template<typename type>
maxheap::maxheap(type vec,const int& size,const int& heap_size){
    length=size;
    heapsize=heap_size;
    if(heapsize>length)
        heapsize=length;
    if(size>0){
        build_max_heap(vec,size,heap_size);
    }
}

int maxheap::left(const int& i){
    return 2*i+1;
}


int maxheap::right(const int& i){
    return 2*i+2;
}

template<typename type>
void maxheap::max_heapify(type vec,const int& i){
    int l=left(i);
    int r=right(i);
    int largest;
    if(l<heapsize && *(vec+l)>*(vec+i))
        largest=l;
    else 
        largest=i;
    if(r<heapsize && *(vec+r)>*(vec+largest))
        largest=r;
        if(largest!=i){
            auto tmp=*(vec+i);
            *(vec+i)=*(vec+largest);
            *(vec+largest)=tmp;
            max_heapify(vec,largest);
        }   
}

template<typename type>
void maxheap::build_max_heap(type vec,const int& size,const int& heap_size){
    length=size;
    heapsize=heap_size;
    if(length<=0) return;
    if(heapsize>length)   heapsize=length;
    int i=(heapsize/2)-1;
    for(;i>=0;--i)
        max_heapify(vec,i);
}


template<typename type>
void maxheap::heapsort(type vec,const int& size){
    build_max_heap(vec,size,size);
    for(int i=length-1;i>0;--i){
        auto tmp=*vec;
        *vec=*(vec+i);
        *(vec+i)=tmp;
        --heapsize;
        max_heapify(vec,0);
    } 
}

maxheap::~maxheap(){
    length=0;
    heapsize=0;
}
