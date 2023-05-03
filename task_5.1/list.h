//
// Created by mac on 19.04.2023.
//

#ifndef TASK_5_1_LIST_H
#define TASK_5_1_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode_t{
    int data;
    unsigned int index;
    struct ListNode_t *next;
}ListNode_t;

typedef struct List_t{
    int listLen;
    struct ListNode_t * pHead;
}List_t;

List_t *listInit();

ListNode_t *push(List_t *pList, int data);

void deleteList(List_t *pList);

void printList(List_t *pList);

ListNode_t *getElement(List_t *pList, unsigned int index);

int sumElem(List_t *pList);

#endif //TASK_5_1_LIST_H
