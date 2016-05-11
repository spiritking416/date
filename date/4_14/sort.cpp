/*************************************************************************
	> File Name: sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月13日 星期三 08时53分25秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include"sort.h"
using namespace std;

//冒泡排序
template<class type>
void bubblesort(type first,type last){
    for(auto it=first;it!=last-1;++it){
        for(auto jt=it+1;jt!=last;++jt){
            if(*it>=*jt){
                auto tmp=*it;
                *it=*jt;
                *jt=tmp;
            }
        }
    }
}

//归并排序
template<class type,class T>
void mergesort(type left,type right,T& val)
{
    if(left>=right) return;
    int m=(right-left)/2;
    auto mid=left+m;
    mergesort(left,mid,val);
    mergesort(mid+1,right,val);
    merge(left,mid,right,val); 
}
template<class type,class T>
void merge(type left,type mid,type right,T& val){
    vector<T> leftvec(left,mid+1);
    vector<T> rightvec(mid+1,right+1);
    unsigned int i=0,j=0;
    for(auto it=left;it<=right;++it){
        if(i<leftvec.size() && j<rightvec.size()){
             
            if(leftvec[i]<rightvec[j])
            {
                *it=leftvec[i];
                ++i;
            }
            else
            {
                *it=rightvec[j];
                ++j;
            }
        }
        else if(i<leftvec.size()){
            *it=leftvec[i];
            ++i;
        }
        else
        {
            *it=rightvec[j];
            ++j;
        }
    } 
}

//快速排序
template<class type>
void quicksort(type left,type right){
    if(left<right)
    {
        auto q=partition(left,right);
        quicksort(left,q-1);
        quicksort(q+1,right);
    }
}

template<class type>
type partition(type left,type right){
    auto x=*right;
    auto i=left-1;
    for(auto it=left;it!=right;++it){
        if(*it<=x){
            ++i;
            auto tmp=*i;
            *i=*it;
            *it=tmp;
        }
    }
    *right=*(i+1);
    *(i+1)=x;
    return (i+1);
}

//计数排序
template<class type>
void counting_sort(type A_begin,type A_end,type B_begin,const int& k){
    vector<int> C(k+1,0);
    for(auto it=A_begin;it!=A_end;++it)
        C[*it]+=1;
    for(int i=1;i<=k;++i)
        C[i]+=C[i-1];
    for(auto it=A_end-1;it>=A_begin;--it){
        *(B_begin+C[*it]-1)=*it;
        C[*it]-=1;
    }
}
