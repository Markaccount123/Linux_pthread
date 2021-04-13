#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

void handler(int sig)
{
  printf("pid : %lu,get a sig , NO. %d\n",getpid(),sig);

}
int main()
{

  signal(SIGCHLD,handler);

  if(fork() == 0){
    printf("child running ....!  pid : %lu, ppid : %lu\n",getpid(),getppid());
    sleep(5);
    printf("child quit!\n");
    exit(1);
  }

  while(1);


  return 0;

}
