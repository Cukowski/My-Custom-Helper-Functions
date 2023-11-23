#include <stdio.h>
#include <stdlib.h>

int my_square(int a, int b)
{
    
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= a; j++) {
            if(i==1||i==b){
                if (j != 1 && j != a) {
                    printf("-");
                }
                else {
                    printf("o");
                }
            }
            else if (j==1||j==a) {
                printf("|");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

int main()
{
    int x, y;
    x = 7;
    y =6;
    
    my_square(x, y);
    return 0;
}

// int main(int ac, char **av)
// {
    
//     if (ac >= 3) {
//         int x = atoi(av[1]);
//         int y = atoi(av[2]);
//         my_square(x, y);
//     }else

//     return 0;
    
// }