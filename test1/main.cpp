#include<iostream>
#include<unistd.h>
#include<stdio.h>
using namespace std;

int main(){
  char buf[1024]={0};
  const char *label="/-\\|";
  int i=0;
  for(;i<100;i++){
    buf[i]='#';
    printf("[%d%%][%c][%s]\r",i,label[i%4],buf);
   //一次git测试
    fflush(stdout);
    usleep(500* 1000);
  }



  return 0;
}
