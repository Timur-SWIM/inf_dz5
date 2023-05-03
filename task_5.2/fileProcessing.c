//
// Created by mac on 29.04.2023.
//

#include "fileProcessing.h"
IndexError_t errorCheck(int argc, char *argv[]){
    if (argc != 2)
        return WRONG_NUM_ARGS;
    return GOOD;
}

FileParams_t *initFileParams(){
    FileParams_t *pFile = malloc(sizeof(FileParams_t));
    pFile->pLine = NULL;
    pFile->lineCount = 0;
    return pFile;
}

Line_t *addNewLine(FileParams_t *pFile){
    Line_t *curLine = pFile->pLine;

    if (curLine != NULL){
        while (curLine->next != NULL){
            curLine = curLine->next;
        }
    }
    Line_t *newLine = malloc(sizeof(Line_t));
    newLine->next = NULL;
    newLine->data = listInit();
    newLine->LineIndex = pFile->lineCount;
    newLine->NumIndex = 0;

    if (curLine == NULL){
        pFile->pLine = newLine;
    } else{
        curLine->next = newLine;
    }
    return newLine;
}

void pushLine(Line_t *pLine, char *str){
    for (int i = 0; i < strlen(str); i++){
        push(pLine->data, str[i]);
    }
}

IndexError_t checkLine(char *str){
    unsigned int len = strlen(str);
    for (int  i = 0; i < len; i++){
        if (isdigit(str[i]) != 0){
            return ISDIGIT;
        }
    }
    return GOOD;
}


IndexError_t inputFilParams(FileParams_t *pFile, const char *filePath){
    FILE *input = fopen(filePath, "rt");
    IndexError_t error;
    if (input == NULL){
        return WRONG_FILE_PATH;
    } else {
        char lineBuf[256];
        while ((fgets(lineBuf, sizeof(lineBuf), input)) != NULL){
            error = checkLine(lineBuf);
            if (error != ISDIGIT){
                Line_t *newLine = addNewLine(pFile);
                pushLine(newLine, lineBuf);
                pFile->lineCount++;
            } else {
                printf("line have number ->%s", lineBuf);
            }
        }
    }
    fclose(input);
    return GOOD;
}

void printFile(FileParams_t *pFile){
    Line_t *curLine = pFile->pLine;
    while (curLine != NULL){
        printf("%d ", curLine->LineIndex);
        printList(curLine->data);
        curLine = curLine->next;
    }
}

void freeFile(FileParams_t *pFile){
    Line_t *curLine = pFile->pLine;
    while (curLine != NULL){
        Line_t *nextLine = curLine->next;
        deleteList(curLine->data);
        free(curLine);
        curLine = nextLine;
    }
    free(pFile);
}

Line_t *getLine(FileParams_t *pFile, unsigned  int index){
    Line_t *curLine = pFile->pLine;
    for (int i = 0; i < index; i++){
        curLine = curLine->next;
        if (curLine == NULL){
            puts("ERROR: Wrong index");
            return NULL;
        }
    }
    return curLine;
}

void printNewCombination(FileParams_t *pFile){
    int lineCount = pFile->lineCount;
    int midNum = lineCount / 2;
    printf("%d\n", midNum);
    for (int i = 0, j = (pFile->lineCount - 1); (i < (midNum+1) && j > (midNum-1)); (i++, j--)){
        Line_t *curLine = getLine(pFile, i);
        Line_t *nextLine = getLine(pFile, j);

        printf("%d ", curLine->LineIndex);
        printList(curLine->data);

        printf("%d ", nextLine->LineIndex);
        printList(nextLine->data);
        //putchar('\n');
    }
}
List_t *nextCombination(FileParams_t *pFile){
    List_t *newComb = listInit();
    Line_t *curLine = pFile->pLine;

    for (int i = 0; i < pFile->lineCount; i++){
        if (curLine->NumIndex >= curLine->data->listLen){
            curLine->NumIndex = 0;
            if (curLine->next != NULL){
                curLine->next->NumIndex++;
            } else{
                return NULL;
            }
        }
        ListNode_t *curElem = getElement(curLine->data, curLine->NumIndex);
        ListNode_t *node = push(newComb, curElem->data);
        node->index = curLine->NumIndex;

        if (curLine->LineIndex == 0){
            curLine->NumIndex++;
        }
        curLine = curLine->next;
    }
    return newComb;
}