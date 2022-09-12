#include <stdio.h>
#include "functions.h"

///Main menu function
int menu(void)
{
    int x, status;

    printf("\n");
    puts(STARS);
    printf("\n--MAIN MENU--\nSelect from the following:\n1)Market Cap Comparison\n"
    "2)Create a Portfolio\n3)Create a Company\n4)Quit\n\n");
    puts(STARS);

    while ((status = scanf("%d", &x)) != 1 || (x < 1 || x > 5))
    {
        if (status != 1)
            scanf("%*s"); // ignores a string input

        printf("Enter an integer from 1 to 4, please: ");
    }

    return x;
}
