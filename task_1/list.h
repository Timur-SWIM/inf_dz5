//
// Created by mac on 13.04.2023.
//

#ifndef TASK_1_LIST_H
#define TASK_1_LIST_H
#include <stdlib.h>
typedef struct list_t{
    int *string;
    int n;
    struct list_t *next;
}list_t;

void push(list_t **head, int *str);
void pop(list_t **head);
list_t* getItem(list_t *head, int n);
void deleteList(list_t **head);
#endif //TASK_1_LIST_H
