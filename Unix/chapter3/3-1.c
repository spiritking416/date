/*************************************************************************
	> File Name: 3-1.c
	> Author: 
	> Mail: 
	> Created Time: Fri 13 May 2016 10:22:05 AM CST
 ************************************************************************/

#include "apue.h"

int main(void){
    if(lseek(STDIN_FILENO,0,SEEK_CUR)==-1)
        printf("cannot seek\n");
    else
        printf("seek ok\n");
    exit(0);
}

