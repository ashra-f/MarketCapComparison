#include <stdio.h>
#include "functions.h"

///portfolio functions
void port(void)
{
    int company_num, index, status;
    char reset;
    float total_assets = 0, holdings[100];

    puts(STARS);
    printf("\n\nYour portfolio is empty. Let's fix that for you!\n");
    printf("\nAvailable companies on this platform:\n");
    printf("1)Apple\n2)Saudi Aramco\n3)Microsoft\n4)Alphabet\n5)Amazon\n");
    printf("6)Tesla\n7)Berkshire Hathaway\n8)UnitedHealth\n9)TSMC\n10)Meta Platforms\n\n");
    puts(STARS);

    ///get number of companys owned
    printf("How many companies do you own (max 10)? ");
    while ((status = scanf("%d", &company_num)) != 1 || (company_num < 1 || company_num > 10))
    {
        if (status != 1)
            scanf("%*s"); // ignores a string input

        printf("Enter an integer from 1 to 10, please: ");
    }

    char name[company_num][100];

    ///get name and amt of companys
    for (index = 0; index < company_num; index++)
    {
        printf("\nAdd a company you own: ");
        scanf("%100s", name[index]);
        holdings[index] = add_company(company_num);
        total_assets += holdings[index];
    }

    puts(STARS);
    printf("\nTotal assets in your portfolio: $%.2f\n",total_assets);
    printf("Your assets:\n");
    printf("Name-\t\tHoldings-\n");

    for (index = 0; index < company_num; index++)
    {
        printf("%s", name[index]);
        printf("\t\t%.2f\n", holdings[index]);
    }
    printf("\n");
    puts(STARS);

    printf("Do you wish to reset your portfolio and try again? [Y/N] \n");
    scanf(" %c", &reset);
    if (reset == 'Y' || reset == 'y')
        port();
}

float add_company(int company)
{
    float price, owned;
    int status1, status2;

    printf("Enter the amount owned: ");
    while((status1 = scanf(" %f", &owned)) != 1)
    {
        if (status1 != 1)
            scanf("%*s"); // ignores a string input
        printf("Invalid input. Re-enter amount owned: ");
    }

    printf("Enter the price target: ");
    while((status2 = scanf("%f", &price)) != 1)
    {
        if (status2 != 1)
            scanf("%*s"); // ignores a string input
        printf("Invalid input. Re-enter price target: ");
    }

    float total = owned * price;

    return total;
}
