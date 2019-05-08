//
// Created by Or Aviv on 2019-05-08.
//

#include "fib_helper.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct elementList_t
{
    long int data;
    struct elementList_t* next;
};

typedef struct uniqueFibList_t
{
    ElementList* head;
    ElementList* fib_zero;
    ElementList element_list;
};

UniqueFibList uniqueFibListCreate (int number)
{
    UniqueFibList new_list = malloc(sizeof(*new_list));
    ElementList first_element = malloc(sizeof(*first_element));
    if (new_list == NULL || first_element == NULL)
    {
        free(new_list);
        free(first_element);
        return NULL;
    }
    if (number > 0)
    {
        ElementList second_element = malloc(sizeof(*second_element));
        if (second_element == NULL)
        {
            free(new_list);
            free(first_element);
            return NULL;
        }
        first_element->data = fib(0);
        second_element->data = fib(1);
        new_list->element_list = second_element;
        new_list->element_list->next = first_element;
        first_element->next = second_element;
        new_list->fib_zero = &first_element;
        new_list->head = &second_element;
        if (newFibList(new_list,number) == UNIQUE_FIB_LIST_SUCCESS)
        {
            first_element->next = new_list->head;
            return new_list;
        }
        else
        {
            uniqueFibListDestroy(new_list);
            return NULL;
        }
    }
    first_element->data = fib(0);
    new_list->element_list  = first_element;
    new_list->head = &first_element;
    new_list->element_list->next = *(new_list->head);
    return new_list;
}

void uniqueFibListPrint (UniqueFibList fibList)
{
    fibList->element_list = *(fibList->head);

    do
        {
            printf("%ld \n",fibList->element_list->data);
            fibList->element_list = fibList->element_list->next;
        }
        while (fibList->element_list->next != *(fibList->head));
}

long int fib(int n)
{
    if (n == 0 || n ==1)
        return 1;

    long int previous_fib = 1;
    long int current_fib  = 1;
    long int new_fib = 0;


    for (int i = 2; i <= n; i++)
    {
        current_fib += previous_fib;
        previous_fib = current_fib;
        current_fib = new_fib;
    }

    return current_fib;
}

UniqueFibListResult newFibList (UniqueFibList list, int number)
{
    long int previous_fib = 1;
    long int current_fib = 1;
    long int new_fib = 0;

    for (int i = 2; i <= number ; i++)
    {
        ElementList element = malloc(sizeof(*element));
        if (element == NULL)
            return UNIQUE_FIB_LIST_NULL_ARGUMENT;
        new_fib = current_fib + previous_fib;
        previous_fib = current_fib;
        current_fib = new_fib;
        element->data = new_fib;
        element->next = *list->head;
        list->head = &element;
    }
    return UNIQUE_FIB_LIST_SUCCESS;

}

void uniqueFibListDestroy(UniqueFibList list)
{
    ElementList* support_node = &list->element_list;
    while (list->element_list != NULL)
    {
        if (list->element_list == *list->fib_zero)
            list->element_list->next = NULL;
        list->element_list = list->element_list->next;
        free(*support_node);
        support_node = &list->element_list;
    }
    free(support_node);
}

void printBadNumberMessage()
{
    printf("Number is not valid, only positive natural numbers are acceptable.");
}