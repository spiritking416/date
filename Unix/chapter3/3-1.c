/*************************************************************************
	> File Name: 3-1.c
	> Author: 
	> Mail: 
	> Created Time: Fri 13 May 2016 10:22:05 AM CST
 ************************************************************************/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(void){
    off_t offset=lseek(STDIN_FILENO,0,SEEK_CUR);
    if(offset==-1)
        printf("cannot seek\n");
    else
    {
        printf("%ld\n",offset);
        printf("seek ok\n");
    }
    exit(0);
}

