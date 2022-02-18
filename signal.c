/* hello_signal.c */
//Collaborated with David Daniels
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>       // for time()
#include "timer.h"

int check = -1;
int timecheck = -1;
int counter = 0;
time_t begin = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  check = 0;
  alarm(1);
  counter++;
}

void handlerCntrlC(int signum)
{ //signal handler
  timecheck = 0;
  time_t end = time(NULL);
  onCntrlC(end-begin, counter);
  exit(0);
}


int main(int argc, char * argv[])
{
  
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT,handlerCntrlC); //register handler to handle SIGALRM
  begin = time(NULL);
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1) { //busy wait for signal to be delivered
    while(check == 0) {
      printf("Turing was right!\n");
      check = -1;
    }
  } 
  return 0; //never reached
}