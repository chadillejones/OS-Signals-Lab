/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "timer.h"

extern timecheck;

void onCntrlC(time_t time, int counter)
{ //signal handler
  printf("\nThe program has tracked %d alarms\n", counter);
  printf("The elapsed time is %d seconds\n", time);
}

