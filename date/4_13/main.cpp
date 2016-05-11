/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月13日 星期三 09时02分50秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include"sort.cpp"
#include"maxheap.cpp"

using namespace std;

int main(){
    int a[]={6,3,0,9,11,2,1};
    vector<int> vec(a,a+7);
    //maxheap max_heap(vec.begin(),size,size);
    //maxheap max_heap;
    //max_heap.heapsort(a,7);                             //堆排序
    //bubblesort(vec.begin(),vec.end());
    //bubblesort(a,a+7);                                  //冒泡排序
    //mergesort(vec.begin(),vec.end()-1,a[0]);            //归并排序
    //mergesort(a,a+6,a[0]);
    //quicksort(a,a+6);
    quicksort(vec.begin(),vec.end()-1);                   //快速排序
    for(auto i:vec){
        cout<<i<<' ';
    }
    cout<<endl;
    for(auto i:a){
        cout<<i<<' ';
    }
    cout<<endl;
}
