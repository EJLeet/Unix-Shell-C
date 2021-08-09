#include "include.h"

void local_time()
{// print local time and data
    time_t true_time;
    struct tm *display_time; // struct for time data
    time(&true_time);
    display_time = localtime(&true_time);
    printf("%s", asctime(display_time));
}