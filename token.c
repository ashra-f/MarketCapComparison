#include <stdio.h>
#include "functions.h"

///token functions
float top_10_mcaps[] = {849.7, 365.4, 66.3, 63.3, 63.0, 46.7, 35.6, 27.0, 21.2, 16.7};
char *standings[] = {"1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th"};
char *top_10[] = {"Apple","Saudi Aramco","Microsoft","Alphabet","Amazon","Tesla","Berkshire Hathaway", "UnitedHealth", "TSMC", "Meta Platforms",""};

void token(void) //make your own company
{
    char reset, view_list;
    int rank = 1;
    struct company *companyPtr, custom_company;
    companyPtr = &custom_company;

    printf("Enter the name of the company: ");
    scanf("%s", companyPtr->name);

    printf("Enter the circulating supply (in billions): ");
    scanf("%f",&companyPtr->supply);

    printf("Enter the market capitalization (in billions): ");
    scanf("%f",&companyPtr->market_cap);

    companyPtr->price = companyPtr->market_cap / companyPtr->supply;

    //based on provided info, tell user where their company is on the top 10 list
    rank = ranking(&custom_company, rank);

    printf("Do you wish to see the updated top ten list? [Y/N]\n");
    scanf(" %c", &view_list);
    if (view_list == 'Y' || view_list == 'y')
    {
        printf("\n%s\nTOP 10 LIST:\n\n", STARS);
        printf("# \t Name\n");
        printf("----------------------\n");
        for(int m=0; m<=(10 - rank); m++)
            top_10[10-m] = top_10[9-m];

        top_10[rank - 1] = companyPtr->name;

        for(int n = 0; n < rank; n++)
            printf("%s \t %s\n", *(standings + n), *(top_10 + n));

        if((companyPtr->market_cap) == *(top_10_mcaps + rank - 1))
        {
            int n = rank - 1;
            printf("%s \t %s\n", *(standings + n), *(top_10 + n + 1));
            for(int n = rank + 1; n < 10; n++)
                printf("%s \t %s\n", *(standings + n), *(top_10 + n));
        }
        else
        {
            for(int n = rank; n < 10; n++)
                printf("%s \t %s\n", *(standings + n), *(top_10 + n));
        }

    }
    printf("\n%s\n\n", STARS);

    printf("Do you wish to create another company? [Y/N] \n");
    scanf(" %c", &reset);
    if (reset == 'Y' || reset == 'y')
        token();
}

int ranking(struct company *Ptr, int rank)
{
    while(Ptr->market_cap < *(top_10_mcaps + rank - 1))
        rank++;

    if (rank > 10)
        printf("\nThe price of %s is $%.2f.\nYour company is outside the top ten list.\n\n", Ptr->name, Ptr->price);

    else
        printf("\nThe price of %s is $%.2f.\nYour company is %s on the top ten list.\n\n", Ptr->name, Ptr->price, *(standings + rank - 1));

    return rank;
}
