//
// Created by mac on 29.04.2023.
//

#ifndef TASK_5_2_FILEPROCESSING_H
#define TASK_5_2_FILEPROCESSING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

typedef enum IndexError_t{
    GOOD,
    WRONG_NUM_ARGS,
    WRONG_FILE_PATH,
    ISDIGIT
}IndexError_t;

typedef struct Line_t{
    struct Line_t *next;
    struct List_t *data;
    unsigned int LineIndex;
    unsigned int NumIndex;
}Line_t;

typedef struct FileParams_t{
    Line_t *pLine;
    unsigned int lineCount;
}FileParams_t;

IndexError_t errorCheck(int argc, char *argv[]);

FileParams_t *initFileParams();

Line_t *addNewLine(FileParams_t *pFile);

void pushLine(Line_t *pLine, char *str);

IndexError_t inputFilParams(FileParams_t *pFile, const char *filePath);

IndexError_t checkLine(char *str);

void printFile(FileParams_t *pFile);

void freeFile(FileParams_t *pFile);

List_t *nextCombination(FileParams_t *pFile);

#endif //TASK_5_2_FILEPROCESSING_H
