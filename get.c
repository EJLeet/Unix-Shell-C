#include "include.h"

int get(char *filename)
{
    char contents;
    int counter = 1;
    FILE *file_ptr = fopen(filename, "r"); // open file and check if it exists
    if (file_ptr == NULL)
    {
        printf("No file %s\n", filename);
        return 0;
    }
    contents = fgetc(file_ptr);
    while (contents != EOF)
    { // read the file and print contents
        if (contents == '\n')
            ++counter;
        printf("%c", contents);
        contents = fgetc(file_ptr); // read file
        while ((counter % 41) == 0)
        { // display first 40 results, continue once enter key is pressed
            contents = fgetc(file_ptr);
            printf("Press enter to continue");
            getchar();
            counter = 1;
            break;
        }
    }
    fclose(file_ptr);
    printf("\n");
    return 0;
}