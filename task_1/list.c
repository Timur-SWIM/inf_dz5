//
// Created by mac on 13.04.2023.
//

#include "list.h"

void push(list_t **head, int *str){
    list_t *tmp = (list_t*) malloc(sizeof(list_t));
    tmp->string = str;
    tmp->next = (*head);
    (*head) = tmp;
}
void pop(list_t **head){
    list_t *prev = NULL;
    if (head == NULL){
        exit(-1);
    }
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
}
list_t* getItem(list_t *head, int n){
    int counter = 0;
    while (counter < n && head){
        head = head->next;
        counter++;
    }
    return head;
}
void deleteList(list_t **head){
    while ((*head)->next){
        pop(head);
        (*head) = (*head)->next;
    }
    free(*head);
}