/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月15日 星期五 23时11分37秒
 ************************************************************************/

#include<stdio.h>

struct s{
    int a;
    char b;
    short c;
};

union p{
    int m;
    char n[10];
    short b;
};

int main(){
    struct s m;
    union p n;
    int g=sizeof(m);
    printf("%d\n",g);
    int h=sizeof(n);
    printf("%d\n",h);
}
