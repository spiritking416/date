/*************************************************************************
	> File Name: 3-5.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 May 2016 10:22:19 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"error.c"

#define BUFFSIZE 4096

int
main(void){
    int n;
    char buf[BUFFSIZE];

    while((n=read(STDIN_FILENO,buf,BUFFSIZE))>0)
        //printf("%d\n",n);
        if(write(STDOUT_FILENO,buf,n)!=n)
            err_sys("write error");

    if(n<0)
        err_sys("read error");
    exit(0);
}
