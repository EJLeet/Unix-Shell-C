#include "include.h"

void path()
{ // get current working directory
    char directory[SIZE];
    if (getcwd(directory, sizeof(directory)) != NULL)
        printf("%s \n", directory);
}