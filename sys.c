#include "include.h"

// void sys() // use if m1 chip mac
// { // retrives and prints system information
//     struct utsname system; // storing system info data in a struct
//     uname(&system);

//     printf("Operating System - %s \n", system.sysname);
//     printf("Release          - %s \n", system.release);
//     printf("Version          - %s \n", system.version);
//     printf("Architecture     - %s \n", system.machine);

//     char temp[SIZE];
//     size_t size = sizeof(temp);
//     if (sysctlbyname("machdep.cpu.brand_string", &temp, &size, NULL, 0) < 0)
//         perror("sysctl");
//     printf("CPU Type         - %s \n", temp);
// }

void sys()                 // use if linux
{                          // retrives and prints system information
    struct utsname system; // storing system info using utsname in a struct
    uname(&system);

    printf("Operating System - %s \n", system.sysname);
    printf("Release          - %s \n", system.release);
    printf("Version          - %s \n", system.version);
    printf("Architecture     - %s \n", system.machine);

    FILE *file_ptr = fopen("/proc/cpuinfo", "r"); // cat cpu info
    char buffer[SIZE];                            // hold each line of cat
    while (fgets(buffer, SIZE, file_ptr) != NULL)
    { // search for model name
        if ((strstr(buffer, "model name")) != NULL)
        { // print model name
          printf("CPU              - %s\n", buffer);
          break;
        }
    }
    fclose(file_ptr);
}