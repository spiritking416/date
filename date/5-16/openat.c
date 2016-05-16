/*************************************************************************
	> File Name: openat.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 May 2016 08:58:44 AM CST
 ************************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int
main(void){
    int fd;
    int dir_fd;
    dir_fd=open("./open",O_RDONLY);
    if(dir_fd==-1){
        printf("dir error\n");
        exit(1);
    }
    printf("%d\n",dir_fd);
    fd=openat(dir_fd,"log.txt",O_RDWR | O_CREAT | O_TRUNC);
    if(fd==-1){
        printf("txt error\n");
        close(dir_fd);
        exit(1);
    }
    close(fd);
    close(fd);
    printf("%d\n",fd);
    printf("success\n");
    exit(0);   
}
