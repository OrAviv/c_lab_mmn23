//
// Created by Or Aviv on 2019-05-08.
//

#ifndef MAMAN23Q2_FIB_HELPER_H
#define MAMAN23Q2_FIB_HELPER_H


typedef struct elementList_t* ElementList;
typedef struct uniqueFibList_t* UniqueFibList;

typedef enum UniqueFibListResult_t {
    UNIQUE_FIB_LIST_SUCCESS,
    UNIQUE_FIB_LIST_NULL_ARGUMENT
} UniqueFibListResult;


UniqueFibList uniqueFibListCreate (int number);
void uniqueFibListPrint (UniqueFibList fibList);
long int fib(int n);
UniqueFibListResult newFibList (UniqueFibList list, int number);
void printBadNumberMessage();
void uniqueFibListDestroy(UniqueFibList list);
void flipList(UniqueFibList list);





#endif //MAMAN23Q2_FIB_HELPER_H
