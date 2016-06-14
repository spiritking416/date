/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 Jun 2016 08:57:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//两个矩阵乘积的标准算法
//ra,ca,rb,cb分别表示矩阵A和B的行数和列数


void matrixMultiply(int** a,int** b,int** c,const int& ra,const int& ca,const int& rb,const int& cb){
    if(ca!=rb) return;
    for(int i=0;i<ra;++i)
    {
        for(int j=0;j<cb;++j){
            int sum=0;
            for(int k=0;k<rb;++k){
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }
}
