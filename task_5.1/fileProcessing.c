//
// Created by mac on 25.04.2023.
//

#include "fileProcessing.h"
IndexError_t errorCheck(int argc, char *argv[]){
    if (argc != 3)
        return WRONG_NUM_ARGS;

    unsigned int len = strlen(argv[2]);
    for (int i = 0; i < len; i++){
        if (!isdigit(argv[2][i]))
            return WRONG_SECOND_ARG;
    }
    return GOOD;
}

FileParams_t *initFileParams(){
    FileParams_t *pFile = malloc(sizeof(FileParams_t));
    pFile->pLine = NULL;
    pFile->LineCount = 0;
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
    newLine->LineIndex = pFile->LineCount;
    newLine->NumIndex = 0;

    if (curLine == NULL){
        pFile->pLine = newLine;
    } else{
        curLine->next = newLine;
    }

    return newLine;
}

void convStrtoIntline(Line_t *pLine, char *str){
    char *strNum = strtok(str, ",");
    while (strNum != NULL){
        int num = atoi(strNum);
        push(pLine->data, num);
        strNum = strtok(NULL, ",");
    }
}

IndexError_t inputFilParams(FileParams_t *pFile, const char *filePath){
    FILE *input = fopen(filePath, "rt");

    if (input == NULL){
        return WRONG_FILE_PATH;
    } else {
        char lineBuf[256];
        while ((fgets(lineBuf, sizeof(lineBuf), input)) != NULL){
            Line_t *newLine = addNewLine(pFile);
            convStrtoIntline(newLine, lineBuf);
            pFile->LineCount++;
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