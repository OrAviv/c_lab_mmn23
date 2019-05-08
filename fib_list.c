#include <stdio.h>
#include "fib_helper.h"

int main()
{
    int number=0;
    printf("Hello!\n"
           "This program will create a Fibonacci list.\n "
           "Please enter a integer equal or greater than zero\n");

    scanf("%d",&number);
    if (number < 0)
        printBadNumberMessage();
    else
    {
        UniqueFibList my_list = uniqueFibListCreate(number);
        uniqueFibListPrint(my_list);
    }

    return 0;
}