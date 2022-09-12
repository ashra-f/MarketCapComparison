#include <stdio.h>
#include "functions.h"

///Market Cap functions
char *all_companys[] = {"Apple","Saudi Aramco","Microsoft","Alphabet","Amazon"};
float Mcap[] = {2605, 2252, 1984, 1440, 1328};
float supply[] = {16.07, 220, 7.46, 6, 10.19};

void mcap(void)
{
    int company1, company2;

    ///prompt user to enter two tokens
    printf("%s\n", STARS);
    printf("\nPick a number corresponding to the company of your choice.\n");
    printf("1)Apple\n2)Saudi Aramco\n3)Microsoft\n4)Alphabet\n5)Amazon\n\n");
    printf("%s\n", STARS);

    printf("\nEnter the two companies you wish to compare: \n");
    while (scanf("%i%i",&company1, &company2) == 2)
    {
        if ((company1 > 5) || (company1 < 1) || ((company2 > 5) || (company2 < 1)))
            printf("Invalid.");
        else if (company1 == company2)
            printf("You entered the company. Try again!\n");
        else
            compare(company1, company2);

        printf("\nEnter the companies (q to quit): \n");
    }
}

void compare(int company1, int company2)
{
    float new_price = 0.0, price, percent_ch;

    new_price =  *(Mcap + company2 - 1) / (supply[company1 - 1]);
    price = *(Mcap + company1 - 1) / (supply[company1 - 1]);
    percent_ch = ((new_price - price)/price) * 100; //percent change equation

    if (percent_ch >= 1000)
    {
        percent_ch /= 100;
        printf("If %s had the same market cap as %s, the new price would be $%.2f. That is a change of %.1fx!\n", all_companys[company1 - 1], all_companys[company2 - 1], new_price, percent_ch);
    }
    else
        printf("If %s had the same market cap as %s, the new price would be $%.2f. That is a change of %.2f%% from the current price!\n", all_companys[company1 - 1], all_companys[company2 - 1], new_price, percent_ch);

}
