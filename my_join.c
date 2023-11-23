#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif


char* my_join(string_array* param_1, char* param_2)
{
    char *temp = (char*) malloc(sizeof(char)*30);
    char *result = (char*) malloc(sizeof(char)*30);

    for (int i = 0; i < param_1->size; i++) {
        temp = param_1->array[i];

        sprintf(result, "%s%s", temp, param_2);

        result = strcat(result, param_1->array[i+1]);
        result = strcat(result, param_2);
        result = strcat(result, param_1->array[i+2]);
        result = strcat(result, param_2);
        result = strcat(result, param_1->array[i+3]);

        return result;
    }

}
