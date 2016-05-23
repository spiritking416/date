/*************************************************************************
	> File Name: 3-12.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 May 2016 04:14:20 PM CST
 ************************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<error.c>

void
set_fl(int fd,int flags)  //flags are file status flags to turn on
{
    int val;

    if((val=fcntl(fd,F_GETFL,0))<0)
        err_sys("fcntl F_GETFL error");

    val |=flags;  //turn on flags

    //val &=~flags;  //turn flags off

    if(fcntl(fd,F_SETFL,val)<0)
        err_sys("fcntl F_SETFL error");
}

int 
main()
{
    int fd;
    fd=open("txt",O_RDWR | O_CREAT);
    char s[]="first write";
    if(fd==-1)
        printf("open error\n");
    if(write(fd,s,sizeof(s))<0)
    {
        close(fd);
        printf("first write error\n");
    }
    if(write(fd,"second write",13)<0){
        close(fd);
        printf("second write error\n");
    }
    set_fl(fd,O_APPEND);

    if(write(fd,"third write",12)<0){
        close(fd);
        printf("third write error\n");
    }
     
    printf("sdfsadf\n");
    close(fd);
}
