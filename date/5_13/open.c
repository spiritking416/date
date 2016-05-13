/*************************************************************************
	> File Name: open.c
	> Author: 
	> Mail: 
	> Created Time: Fri 13 May 2016 10:51:02 AM CST
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>

int main(void){
    int fd=open("name",O_RDWR | O_CREAT | O_TRUNC);
    if(-1==fd)
        printf("open error\n");
    else
    {
        printf("%d\n",fd);
        printf("open ok\n");
        close(fd);
    }

    fd=openat(fd,"xx/name",O_RDWR | O_CREAT | O_TRUNC);
    if(-1==fd)
        printf("open error\n");
    else
    {
        printf("%d\n",fd);
        printf("open ok\n");
        close(fd);
    }

    
    exit(0);
}


