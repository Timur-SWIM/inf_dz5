#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[]){
    FILE *data;
    data = fopen(argv[1], "rt");
    list_t *head = NULL;
    char str[100];
    int line[100];
    int i = 0;
    char *token;
    while (fgets(str, sizeof(str), data) != NULL){
        printf("%s", str);
        token = strtok(str, ",");
        while (token != NULL){
            printf("token->%s\n", token);
            line[i] = atoi(token);
            printf("int token -> %d\n", line[i]);
            i++;
            token = strtok(NULL, ",");
        }
        push(&head, line);
        head->n = i;
        for (int j = 0; j < i; j++){
            printf("%d ", line[j]);
        }
        printf("\n");
        /*for (int j = 0; j < i + 1; j++){
            line[i] = '-';
        }*/
        i = 0;
    }
    list_t *string1;
    string1 = getItem(head, 1);
    for (int k = 0; k < string1->n + 1; k++){
        printf("str1->%d", string1->string[k]);
    }

    deleteList(&head);
    return 0;
}