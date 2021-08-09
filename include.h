#ifndef SOURCE_DATA
#define SOURCE_DATA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sys/sysctl.h>  // used by sys() for mac m1
#include <sys/utsname.h> // used by sys()
#include <sys/stat.h>    // used by put()
#include <unistd.h>      // used by path()
#include <time.h>        // used by time()
#include <ctype.h>       // isdigit() for calc()
#include <stdbool.h>     // used by calc()

#define SIZE 1024

void calc(char *expression[], int counter);
void local_time();
void path();
void sys();
void put(char *dirname, char *filenames[], char *optional, int counter);
int get(char *filename);
void quit();

#endif