/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 May 2016 02:42:08 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int
main(void){
    int fd;
    fd=open("txt",O_RDWR | O_CREAT);
    if(fd==-1)  printf("open error\n");
    else printf("ok\n");
    printf("%d\n",fd);
    if(write(fd,"ssdfasdfsdfgsdfg",2)<0)
        //printf("write error\n");
    printf("%d\n",O_ACCMODE);
    exit(1);
}
