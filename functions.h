#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define STARS "************************"
#define FIRST 1

struct company
{
    char name[100];
    float supply;
    float market_cap;
    float price;
};

int menu(void);

//first choice
void mcap(void);
void compare(int company1, int company2);

//second choice
void port(void);
float add_company(int company);

//third choice
void token(void);
int ranking(struct company *Ptr, int rank);

#endif // FUNCTIONS_H_INCLUDED
