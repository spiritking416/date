/*************************************************************************
	> File Name: sort.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月13日 星期三 08时53分11秒
 ************************************************************************/

#ifndef _SORT_H
#define _SORT_H

//冒泡排序
template<class type>
void bubblesort(type first,type last);

//归并排序
template<class type,class T>
void mergesort(type left,type right,T& val);
template<class type,class T>
void merge(type left,type mid,type right,T& val);

//快速排序
template<class type>
void quicksort(type left,type right);
template<class type>
type partition(type left,type right);


//计数排序
template<class type>
void counting_sort(type A_begin,type A_end,type B_begin,type B_end,const int& k);

//桶排序
template<class type>
void bucket_sort(type A_begin,type A_end,type B_begin,type B_end,const int& k);

#endif
