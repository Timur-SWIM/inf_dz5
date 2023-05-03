//
// Created by mac on 03.05.2023.
//

#include "list.h"

List_t *listInit(){
    List_t *newList = malloc(sizeof(List_t));
    newList->pHead = NULL;
    newList->listLen = 0;
    return newList;
}

ListNode_t *push(List_t *pList, char data){
    ListNode_t *curElem = pList->pHead;
    if (curElem != NULL){
        while (curElem->next != NULL){
            curElem = curElem->next;
        }
    }
    ListNode_t *newElem = malloc(sizeof(ListNode_t));
    newElem->data = data;
    newElem->index = pList->listLen;
    newElem->next = NULL;
    if  (curElem == NULL){
        pList->pHead = newElem;
    } else {
        curElem->next = newElem;
    }
    pList->listLen++;

    return newElem;
}

void deleteList(List_t *pList){
    ListNode_t *curElem = pList->pHead;
    while (curElem != NULL){
        ListNode_t *nextElem = curElem->next;
        free(curElem);
        curElem = nextElem;
    }
    free(pList);
}

void printList(List_t *pList){
    ListNode_t *curElem = pList->pHead;
    while (curElem != NULL){
        printf("%c", curElem->data);
        curElem = curElem->next;
    }
}

ListNode_t *getElement(List_t *pList, unsigned int index){
    ListNode_t *curElem = pList->pHead;
    for (int i = 0; i < index; i++){
        curElem = curElem->next;
        if (curElem == NULL){
            puts("ERROR: Wrong index");
            return NULL;
        }
    }
    return curElem;
}

