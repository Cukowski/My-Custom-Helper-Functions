#include <stdio.h>
#include <stdlib.h>

int* my_range(int param_1, int param_2)
{
    if(param_1 > param_2){
        int temp = param_1;
        param_1 = param_2;
        param_2 = temp;
    }
    int size = param_2 - param_1 + 1;
    int *result = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        result[i] = param_1 + i;
    }
    return result;
}


int main()
{
    my_range(1, 4);
    
    return 0;
}
