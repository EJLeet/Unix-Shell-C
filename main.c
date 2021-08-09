#include "include.h"

int main(void)
{
    printf("\n2803ICT Assignment 1 Milestone 1\n\nAuthor: Ethan Leet - s5223103\n\n");
    printf("Welcome to Unix shell in c\n\nType 'help' for a list of available commands and their arguements\n\n");

    int size = SIZE;    // define max input size
    char command[size]; // allocate space to command array

    while (1)
    { // loop until quit has been entered
        printf(">>>  ");
        fgets(command, size, stdin); // read in command from user input

        if ((strncmp(command, "calc", 4) == 0) && strlen(command) > 6)
        { // run calc function if a valid command
            char *calc_arg[size];
            char *token = strtok(command, " ");
            int counter = 0;
            while (token != NULL)
            { // read in arguments to be passed to calc function
                calc_arg[counter++] = token;
                token = strtok(NULL, " ");
            }
            char *expression[counter];
            for (int i = 1; i < counter; i++)
                expression[i] = calc_arg[i];

            calc(expression, counter);
            memset(calc_arg, 0, sizeof(calc_arg)); // clear calc
        }

        else if (strcmp(command, "time\n") == 0)
            local_time();
        // run time function if valid command
        else if (strcmp(command, "path\n") == 0)
            path();
        // run path function if valid command
        else if (strcmp(command, "sys\n") == 0)
            sys();
        // run system function if valid command
        else if ((strncmp(command, "put", 3) == 0) && strlen(command) > 5)
        { // run put function if valid command
            char *put_arg[size];
            char *dirname, *optional;
            char *token = strtok(command, " ");
            int counter = 0;
            while (token != NULL)
            { // read in arguements to be passed to put function
                put_arg[counter++] = token;
                token = strtok(NULL, " ");
            }
            char *filenames[counter];
            if (strcmp(put_arg[counter - 1], "-f\n") == 0)
            { // if -f was entered run put with overwrite privilidges
                dirname = put_arg[1];
                optional = put_arg[counter - 1];
                for (int i = 2; i < counter - 1; i++)
                    filenames[i] = put_arg[i];
                put(dirname, filenames, optional, counter);
            }
            else if (put_arg[1] && put_arg[2])
            { // run put command without overwrite privilidges
                dirname = put_arg[1];
                optional = "none";
                for (int i = 2; i < counter; i++)
                    filenames[i] = put_arg[i];
                put(dirname, filenames, optional, counter);
            }
            else
                printf("Error! Invalid command\n");
            memset(filenames, 0, sizeof(filenames)); // clear filenames array
            memset(put_arg, 0, sizeof(put_arg));     // clear put_arg array
        }

        else if ((strncmp(command, "get", 3) == 0) && strlen(command) > 5)
        { // run get function if valid command
            char *get_arg[size];
            int counter = 0;
            char *token = strtok(command, " ");
            while (token != NULL)
            { // read in arguements to be passed to get function
                get_arg[counter++] = token;
                token = strtok(NULL, " ");
            }
            if (counter >= 3)
                printf("Error! Invalid command\n"); // make sure nothing entered after filename
            else
            {
                strtok(get_arg[1], "\n"); // remove newline character
                get(get_arg[1]);          // pass filename to get function
            }
            memset(get_arg, 0, sizeof(get_arg)); // clear get_arg array
        }

        else if (strcmp(command, "quit\n") == 0)
        {
            printf("Program will now terminate\n");
            exit(0);
        }

        else if (strcmp(command, "help\n") == 0)
        {
            printf("\nAvailable Commands:\n\n");
            printf("'calc' 'expression':                        must be a valid prefix expression, be space seperated and accepts '+' or '-'\n");
            printf("'time':                                     prints the current local date and time\n");
            printf("'path':                                     prints the current working directory\n");
            printf("'sys':                                      prints OS and CPU info\n");
            printf("'put' 'directory' 'filename(s)' '[-f]':     creates a new directory named directory (if it doesnt exist)\n");
            printf("                                            copies file(s) to that directory\n");
            printf("                                            if '-f' is specified the directory and its contents will be overwritten\n");
            printf("'get' 'filename':                           prints the file to the screen 40 lines at a time\n");
            printf("'quit':                                     terminates the shell\n\n");
        }

        else
            printf("Error! Invalid command\n");

        memset(command, 0, sizeof(command)); // clear command
    }
}