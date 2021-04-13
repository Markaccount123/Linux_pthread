#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>

void *thread_run(void *arg)
{
  while(1){
    printf("I am %s, pid : %d ,my thread id is %p\n",(char*)arg,getpid(),pthread_self());
    sleep(1);
    int a = 1 / 0;
  }
}


int main()
{
  pthread_t tid;
  //你新创建的线程id就会放在tid中
  pthread_create(&tid,NULL,thread_run,(void*)"thread 1");

  while(1){
    printf("I am main thread id : %p,new thread  : %p, pid : %d\n",pthread_self(),tid,getpid());
    sleep(2);
  }

  return 0;
}
