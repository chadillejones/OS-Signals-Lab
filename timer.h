#ifndef TIMER_H    /* This is an "include guard" */
#define TIMER_H    /* prevents the file from being included twice. */
                     /* Including a header file twice causes all kinds */
                     /* of interesting problems.*/
#include <time.h>       // for time()
/**
 * This is a function declaration.
 * It tells the compiler that the function exists somewhere.
 */
void onCntrlC(time_t time, int counter);

#endif /* TIMER_H */