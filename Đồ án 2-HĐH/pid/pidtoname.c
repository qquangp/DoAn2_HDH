#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/tty.h>
#include <linux/string.h>
#include "pidtoname.h"
asmlinkage long pidtoname(int pid, char* buf, int len){
    struct task_struct *task;
    /*tty struct*/
    struct tty_struct *my_tty;
    /*get current tty*/
    my_tty = get_current_tty();
    for_each_process(task){
        if((int)task_pid_nr(task) == pid){
	    int n = strlen(task->comm);
	    copy_to_user(buf,task->comm, len -1);
            if(len-1 >= n){
                return 0;
            }
            else if(len-1 < n){
                return n;
            }
        }
    }
    return -1;
}