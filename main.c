#include <stdio.h>
#include "functions.h"

int main(void) //Project
{
    int input;

    while ((input = menu()) != 4)
    {
        switch(input)
        {
        case 1: mcap();
                break;
        case 2: port();
                break;
        case 3: token();
                break;
        }
    }

    printf("Goodbye!\n");

    return 0;
}
