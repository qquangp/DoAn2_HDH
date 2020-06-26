#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>
int main(){
    int pid;
    char name[32];
    puts("Enter process ID to find");
    scanf("%d",&pid);
    long int status = syscall(355, pid, name, 32); //syscall number 355 and passing in the string.
    if (status != -1)
        printf("Process name: %s\n", name);
    printf("System call returned %ld\n", status);
    return 0;
}