#include "include.h"

void put(char *dirname, char *filenames[], char *optional, int counter)
{
    char contents;        // used to read source and write to destination file
    char dest[SIZE] = ""; // destination folder path array
    if (strcmp(optional, "none") == 0)
    {                                   // if no -f
        if (mkdir(dirname, 0700) == -1) // check if directory exists
            printf("Error! Directory Already Exists\n");
        else
        { // if it doesn't exist create and copy files
            for (int i = 2; i < counter; i++)
            {                          // loop through each file
                strcat(dest, dirname); // concatenate destination folder with appropriate slashes and filenames
                strcat(dest, "/");
                strcat(dest, filenames[i]);
                filenames[i][strcspn(filenames[i], "\n")] = 0; //strip newline char
                dest[strcspn(dest, "\n")] = 0;                 // strip newline char
                FILE *source_fptr = fopen(filenames[i], "r");  // open source file to be copied
                if (source_fptr == NULL)
                { // if file not found, remove the created directory and print error
                    printf("File %s not found\n", filenames[i]);
                    rmdir(dirname);
                }
                else
                {                                       // save source to destination
                    FILE *dest_fptr = fopen(dest, "w"); // create destination file
                    contents = fgetc(source_fptr);
                    while (contents != EOF)
                    { // loop through source file and save to destination file
                        fputc(contents, dest_fptr);
                        contents = fgetc(source_fptr);
                    }
                    fclose(dest_fptr);
                }
                fclose(source_fptr);
                memset(dest, 0, sizeof(dest));
            }
        }
    }

    else
    {                                      // if -f
        char remove[SIZE] = "exec rm -r "; // string used for removing of files
        strcat(dest, dirname);             // concatenate destination folder with appropriate slashes to bee used by remove
        strcat(dest, "/");
        strcat(remove, dest); // concatenate remove string with the passed directory name
        strcat(remove, "*");  // * to remove all files
        system(remove);       // remove all files
        mkdir(dirname, 0700); // create dir name
        for (int i = 2; i < counter - 1; i++)
        {                                  // loop through each filename
            memset(dest, 0, sizeof(dest)); // clear memset
            strcat(dest, dirname);         // concatenate destination folder with appropriate slashes and filenames
            strcat(dest, "/");
            strcat(dest, filenames[i]);                    // concatenate destination folder with filenames
            filenames[i][strcspn(filenames[i], "\n")] = 0; //strip newline char
            dest[strcspn(dest, "\n")] = 0;                 // strip newline char
            FILE *source_fptr = fopen(filenames[i], "r");  // open source file
            if (source_fptr == NULL)
            { // if file not found, remove the created directory and print error
                printf("File %s not found\n", filenames[i]);
                rmdir(dirname);
            }
            else
            {                                       // save source to destination
                FILE *dest_fptr = fopen(dest, "w"); // create destination file
                contents = fgetc(source_fptr);
                while (contents != EOF)
                { // loop through source file and save to destination file
                    fputc(contents, dest_fptr);
                    contents = fgetc(source_fptr);
                }
                fclose(dest_fptr);
            }
            fclose(source_fptr);
            memset(dest, 0, sizeof(dest));
        }
        memset(remove, 0, sizeof(remove));
    }
}
