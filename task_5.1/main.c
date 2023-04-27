#include "list.h"
#include "fileProcessing.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    IndexError_t error = errorCheck(argc, argv);
    switch (error) {
        case WRONG_NUM_ARGS:
            puts("ERROR: wrong numbers of arguments");
            break;
        case WRONG_SECOND_ARG:
            puts("ERROR: wrong second argument");
            break;
    }
    if (error != GOOD){
        exit(error);
    }
    FileParams_t *file = initFileParams();
    error = inputFilParams(file, argv[1]);

    if (error != GOOD){
        puts("ERROR: wrong file path or file cannot be opened");
        exit(error);
    }
    printFile(file);
    putchar('\n');

    List_t *list = nextCombination(file);
    int fnum = atoi(argv[2]);
    int flag = 0;
    while (list != NULL){
        if (sumElem(list) == fnum){
            printList(list);
            flag = 1;
        }
        //printList(list);
        deleteList(list);
        list = nextCombination(file);
    }
    if (flag != 1){
        puts("No sum");
    }
    freeFile(file);
    return 0;
}